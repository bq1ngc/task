import os
import math
try:
    a,b,c=eval(input("Please input a,b,c!:"))
    dis=math.sqrt(b*b-4*a*c)
    root1=(-b+dis)/(a<<1)
    root2=(-b-dis)/(a<<1)
    print("The quadratic has roots:",root1,"and",root2)
except ValueError as excObj:
    if str(excObj)=="math domain error":
        print("No real roots.")
    else:
        print("Your a,b ares not right number!")
except NameError:
    print("Are you sure you have three numbers?")
except TypeError:
    print("The number! Not auther!")
except SyntaxError:
    print("Syntax Error! Please check your input.The format!")
except:
    print("What's wrong with you? Yet,this is me...")
os.system("pause")