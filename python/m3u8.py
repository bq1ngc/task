#!/usr/bin/env python3
# -*- coding: UTF-8 -*-

"""
@des: Aqniu m3u8 aes decode script, 个人学习使用
@author: XinRoom
"""

import os
import time
import requests
from Crypto.Cipher import AES
from binascii import a2b_hex
import argparse

parser = argparse.ArgumentParser(description="Aqniu m3u8 decode/0.1")
parser.add_argument('-u', '--url', required = True, help='Frist m3u8 url')
parser.add_argument('-n', '--name', required = True, help='Store name 要存储的文件名')
parser.add_argument('-t', '--time',  nargs='?', type=int, default=500, help='Sleep time 每次请求的延迟时间(毫秒)')

args = parser.parse_args()


Downdir = 'm3u8' #默认存储在脚本目录下的m3u8文件夹下
Headers = {
    'Origin': 'https://service-cdn.qiqiuyun.net',
    'Referer': 'https://service-cdn.qiqiuyun.net/js-sdk/video-player/1.1.49/player.html',
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/73.0.3683.86 Safari/537.36'
}

# URL请求会话
s = requests.Session()
s.headers.update(Headers)
num = 1

def key_de(key):
    '''key 解密'''

    return key

    ast = int(key[0],36) % 7
    fc = key[ast]
    sc = key[ast+1]
    anu = int(fc+sc, 36) % 3
    if anu == 1:
        t = '0-1-2-3-4-5-6-7-18-16-15-13-12-11-10-8'
    elif anu == 0:
        t = '0-1-2-3-4-5-6-7-8-10-11-12-14-15-16-18'
    else:
        return -1
    tt = ''
    for s in t.split('-'):
        tt += key[int(s)]
    return tt



def down(m3u8url, m3u8name, downdir):
    '''下载主函数'''

    global num, s
    # 找文件名
    #pos_point = m3u8path.rfind('.')
    #if pos_point == -1:
    #    pos_point = len(m3u8path)
    #pos_backslash = m3u8path.rfind('/')
    #if pos_backslash == -1:
    #    pos_backslash = 0
    #filename = m3u8path[pos_backslash:pos_point]
    filename = m3u8name

    # 创建路径
    filedir = downdir + '/' + filename
    if not os.path.exists(filedir):
        os.mkdir(filedir)

    # 获取高清m3u8链接
    res = s.get(m3u8url).text.split('\n')[-1]   # 高清链接是列表的最后一个
    res = s.get(res)
    allnum = res.text.count('EXTINF')
    with open(os.path.join(filedir, filename + 'gaoqing' + ".m3u8"), 'wb') as f:
        f.write(res.content)

    # 解密处理后的m3u8 文件头
    with open(os.path.join(filedir, filename + ".m3u8"), 'w') as f:
        f.write("#EXTM3U\n#EXT-X-VERSION:3\n\n")
    
    # 解析m3u8
    print('开始解析m3u8文件')
    with open(os.path.join(filedir, filename + 'gaoqing' + ".m3u8"), 'r') as f1:
        key_url_old = ''
        list1 = f1.readlines()
        for index,line in enumerate(list1):
            if "#EXT-X-KEY" in line:  # 找解密Key
                paremeter = line[11:].split(',')
                for pl in paremeter:
                    pll = pl.split('=')
                    if pll[0] == 'METHOD':
                        key_method = pll[1]
                    elif pll[0] == 'URI':
                        key_url = pll[1][1:-1]
                    elif pll[0] == 'IV':
                        key_iv = a2b_hex(pll[1][2:-1])
                
                if key_url_old != key_url:
                    res = s.get(key_url)
                    key = key_de(res.text)
                    print("出现了新Key:",key_method, key_url, key_iv, key)
                key_url_old = key_url
                
                
            elif "EXTINF" in line:  # 找加密后的ts链接
                print("开始第 %d 个块的下载和解密, 共 %d 块" % (num,allnum) )
                
                pd_url = list1[index + 1][:-1]
                res = s.get(pd_url)

                # AES 解密
                cryptor = AES.new(key.encode(), AES.MODE_CBC, key_iv)  
                with open(os.path.join(filedir, str(num) + ".ts"), 'wb') as f:
                    f.write(cryptor.decrypt(res.content))
                with open(os.path.join(filedir, filename + ".m3u8"), 'a') as f:
                    f.write(line)
                    f.write(str(num) + ".ts\n")
                num += 1
                time.sleep(args.time / 1000)

    # 解密处理后的m3u8 文件尾
    with open(os.path.join(filedir, filename + ".m3u8"), 'aw') as f:
        f.write("#EXT-X-ENDLIST")
    
    print("处理完毕")




down(args.url, args.name, Downdir)

