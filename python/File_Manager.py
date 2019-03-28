# -*-coding: utf-8-*-

import os,stat
from time import sleep
from tkinter import *
from tkinter import ttk
import time
import datetime

'''把时间戳转化为时间: 1479264792 to 2016-11-16 10:53:12'''
def TimeStampToTime(timestamp):
    timeStruct = time.localtime(timestamp)
    return time.strftime('%Y/%m/%d %H:%M',timeStruct)

'''获取文件的大小,结果保留两位小数，单位为MB'''
def get_FileSize(filePath):
    fsize = os.path.getsize(filePath)
    fsize = fsize/float(1024)
    return str(round(fsize,2))+"K"

'''获取文件的访问时间'''
def get_FileAccessTime(filePath):
    t = os.path.getatime(filePath)
    return TimeStampToTime(t)

'''获取文件的创建时间'''
def get_FileCreateTime(filePath):
    t = os.path.getctime(filePath)
    return TimeStampToTime(t)


'''获取文件的修改时间'''
def get_FileModifyTime(filePath):
    t = os.path.getmtime(filePath)
    return TimeStampToTime(t)

'''获取文件的扩展名'''
def get_FilExtension(filePath): 
    return os.path.splitext(filePath)[-1][1:]

'''获取文件的状态信息'''
def get_FileStat(filePath):
    t = os.stat(filePath).st_mode
    return stat.filemode(t)

'''获取文件的块信息'''
def get_FileDev(filePath):
    t = os.stat(filePath).st_ino
    return t

class DirList(object):

    def __init__(self, initdir=None):
        self.top = Tk()
        self.top.resizable(0,0)
        self.top.title("文件管理器")

        self.cwd = StringVar(self.top)
        self.ospath = StringVar(self.top)
        self.ospath.set(os.getcwd())
        self.dirl = Entry(self.top, textvariable=self.cwd)
        self.dirl.bind('<Return>', self.doLS)
        self.dirl.pack(fill=X)

        self.dirfm = Frame(self.top)
        self.dirsb = Scrollbar(self.dirfm)  # 滚动条
        self.dirsb.pack(side=RIGHT, fill=Y)
        self.dirs = ttk.Treeview(self.dirfm, show="headings", height=20, columns=("a", "b", "c", "d", "e", "f", "g"),yscrollcommand=self.dirsb.set)
        self.dirs.bind('<Double-1>',
                       self.setDirAndGo)  # 绑定回调函数setDirAndGo，
        self.dirsb.config(command=self.dirs.yview)
        self.dirs.pack(side=LEFT, fill=BOTH)
        self.dirfm.pack(fill=BOTH)


        # 表格的标题
        self.dirs.column("a", width=250)
        self.dirs.column("b", width=100)
        self.dirs.column("c", width=100)
        self.dirs.column("d", width=50)
        self.dirs.column("e", width=80,anchor="e") #, anchor="center"
        self.dirs.column("f", width=80)
        self.dirs.column("g", width=110)
        self.dirs.heading("a", text="文件名")
        self.dirs.heading("b", text="创建时间")
        self.dirs.heading("c", text="修改时间")
        self.dirs.heading("d", text="类型")
        self.dirs.heading("e", text="大小")
        self.dirs.heading("f", text="属性")
        self.dirs.heading("g", text="ino")

        # 初始化GUI程序，从当前目录开始。
        if initdir:
            self.doLS()

    # 列表框回调函数
    def setDirAndGo(self, ev=None):
        item_text=''
        for item in self.dirs.selection():
            item_text = self.dirs.item(item,"values")
        
        if not item_text:
            check = os.getcwd()
        else:
            check = item_text[0]
        self.cwd.set(os.getcwd()+"\\"+check)  # 将cwd跟踪至列表框中某项目录
        self.doLS()

    # 整个GUI程序的关键
    def doLS(self, ev=None):
        # 安全检查
        error = ''
        tdir = self.cwd.get()
        if not tdir: tdir = os.curdir

        if not os.path.exists(tdir):  # 文件不存在
            error = tdir + ': no such file'
        elif not os.path.isdir(tdir):  # 文件路径不存在
            error = tdir + ': not a directory'
            os.startfile(tdir)

        if error:
            self.top.update()
            self.cwd.set(os.getcwd())
            return

        self.top.update()
        dirlist = os.listdir(tdir)  # 列出文件目录tdir下所有文件
        
        os.chdir(tdir)  # 将当前工作目录设置为tdir

        dirls=[]
        filels=[]
        for eachFile in dirlist:
            if os.path.isdir(eachFile):
                dirls.append(eachFile)
            else:
                filels.append(eachFile)
        dirls.sort(key=lambda x: x.lower())  # 排序
        filels.sort(key=lambda x: x.lower())

        x=self.dirs.get_children()
        for item in x:
            self.dirs.delete(item)
            
        self.dirs.insert('','end',values=[os.pardir])
        for eachFile in dirls:
            self.dirs.insert('','end',values=[eachFile,get_FileCreateTime(eachFile),get_FileModifyTime(eachFile),"Dir",'',get_FileStat(eachFile)])
        for eachFile in filels: 
            self.dirs.insert('','end',values=[eachFile,get_FileCreateTime(eachFile),get_FileModifyTime(eachFile),get_FilExtension(eachFile) \
                                ,get_FileSize(eachFile),get_FileStat(eachFile),get_FileDev(eachFile)])

        self.cwd.set(os.getcwd())


def main():
    DirList(1)
    mainloop()


if __name__ == "__main__":
    main()
