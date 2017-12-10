import turtle
def tree(long,pen):
    if long > 40:
        if long<80:
            pen.color("green")
        pen.forward(long)
        pen.color("brown")
        pen.right(30)
        tree(long/6*5,pen)
        pen.left(60)
        pen.forward(long)
        pen.backward(long)
        tree(long/6*5,pen)
        pen.right(30)
        pen.color("brown")
        if long<80:
            pen.color("green")
        pen.backward(long)
   
def main():
    pen = turtle.Turtle()
    screen = turtle.Screen()
    pen.left(90)
    pen.up()
    pen.backward(300)
    pen.down()
    pen.color("brown")
    pen.pensize(2)
    #pen.speed(1)
    tree(155,pen)
    screen.exitonclick()
main()