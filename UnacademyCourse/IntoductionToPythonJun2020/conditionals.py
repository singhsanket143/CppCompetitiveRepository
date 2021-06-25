if 2 >3 : 
    print("Hi")
elif(2 < 5) : # equivalent to else if
    print("hello")


if(True):
    if(10 > 3) :
        if(5 > 3):
            print("you reached")
else:
    print("very far")


# given a number check whether the number is a fibonacci or not ? 
from math import sqrt
n = 13
val1 = 5*(n*n) + 4
val2 = 5*(n*n) - 4

v1 = int(sqrt(val1))
v2 = int(sqrt(val2))
if(v1*v1 == val1 or v2*v2 == val2):
    print("yes")
else:
    print("no")
