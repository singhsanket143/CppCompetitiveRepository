def fun(x, y):
    return x*y, x+y, x-y, x/y

def greet(s) -> str: # type hint
    print("hi there %s %d"%(s, 10))
    return f'Hello {s}'

print(type(fun(4,5)))
print(greet("Saswat"))
