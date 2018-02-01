# encoding: utf-8

__author__ = {  'name' : 'XinRoom',
                'blog' : 'https://www.xinroom.cn/',
                'created' : '2018-01-19',
                'ps' : '一次完整的python作业V3'
              }
 
import random
from tkinter import *
from tkinter.messagebox import *

root = Tk()
root.title("一个小游戏")
root.geometry('310x350+200+100')
#root.iconbitmap('favicon.ico')

LF = LabelFrame(height = 50,width = 250,text = "选择游戏")
cv = Canvas(root,width=110,height=100)


f = open(".\word.txt","w")
f.write('mother\nmhadow\nfigure\ngalaxy\nmoment\nbubble\nbetter\nwonder\ngoodly')
f.close()

def rand():
    e = int(random.random()*10)
    if e>6:
        return 1
    else:
        return e
    
class People:
    def __init__(self):
        self.data=cv
        self.start=1
        self.frit=1
    def head(self):
        if self.frit==0 or self.start==0:
            showinfo(title='提示', message = "请点击在玩一次!")
            return
        self.start=0
        t.val=[]
        t.real=0
        t.line()
        self.data.create_oval(25, 30, 35, 40, tags = "two")
        self.data.after(2000,self.body)
    def body(self):
        self.data.create_line(30, 40, 30, 57, tags = "two")
        self.data.after(2000,self.hand)
    def hand(self):
        self.data.create_line(30, 45, 20, 40, tags = "two")
        self.data.create_line(30, 45, 40, 40, tags = "two")
        self.data.after(1000,self.foot)
    def foot(self):
        self.data.create_line(30, 57, 20, 62, tags = "two")
        self.data.create_line(30, 57, 40, 62, tags = "two")
        self.start=1
        self.frit=0
        if t.val !=1:
            t.capche(1)
    def dell(self):
        self.frit=1
        if(self.start==1):
            for i in self.data.find_withtag('two'):
                self.data.delete(i)
            self.data.after(500,self.head)
        else:
            showinfo(title='提示', message = "请等待绘制完成!")
p=People()

class Text:
    def __init__(self):
        self.data = ''
        f = open(".\word.txt","r")
        lines = f.readlines()
        self.linw = lines[rand()]
        self.text = {}
        self.e = {}
        self.mun = [0,1,2,3,4,5]
        for i in self.mun:
            self.e[i] = StringVar()
        self.val = []
        self.real = 0
    def showText(self,a):
        if self.data == 'disabled':
            print(self.linw[a])
            self.val.append(self.linw[a])
            return self.linw[a]
        else:
            self.val.append(self.linw[a])
            return ''
    def ifShow(self):
        if(random.random()>0.4):
            self.data ='normal'
        else:
            self.data ='disabled'
        return self.data
    def goNext(self,i,a):
        ii = i = int(i)
        if self.real==1 and i<5:
            while(i<5):
                if self.text[i+1]['state'] == 'normal':
                    self.text[i+1].focus_set()
                    break
                i=i+1
                if i==5 and a!='':
                    self.e[ii].set(a)
                    self.capche(1)
        elif i==5 and a!='':
            self.e[i].set(a)
            self.capche(1)
        return True
    def line(self):
        goNextCommand = root.register(self.goNext)
        for i in self.mun:
            self.text[i] = Entry(root,state = self.ifShow(), textvariable = self.e[i], width=2, validate='key', validatecommand=(goNextCommand, i,'%S'))
            self.e[i].set(self.showText(i))
            self.text[i].place(relx=0.4+0.05*i,rely=0.5)
        for i in self.mun:
            cc = self.text[i]
            if cc['state'] == 'normal':
                self.text[i].focus_set()
                break
        self.real=1
        print(self.val)
    def capche(self,e):
        if p.start == 1:
            showerror(title='提示', message = "超时!")
            return
        e=[]
        for i in self.mun:
            e.append(self.text[i].get())
        if e == self.val:
            self.val=1
            showinfo(title='提示', message = "猜词正确!")
        else:
            showerror(title='提示', message = "猜词错误!")

        
t=Text()
    
def start():
    cv.create_line(0, 100, 120, 100, fill="black",width=3)
    cv.create_line(60, 100, 60, 10, width=2)
    cv.create_line(60, 10, 30, 10, width=2)
    cv.create_line(30, 10, 30, 30, width=2)

    
def stop():
    quit()


b1 = Button(LF,text="开始游戏",command=p.head)
b2 = Button(LF,text="再玩一次",command=p.dell)
b3 = Button(LF,text="结束游戏",command=stop)

b1.grid(row=1,column=1,padx=10,pady=10)
b2.grid(row=1,column=2,padx=10,pady=10)
b3.grid(row=1,column=3,padx=10,pady=10)

LF.pack(pady=15)

start()

p.data.place(relx=0.1,rely=0.4)

root.bind("<Return>", t.capche)

root.mainloop()
