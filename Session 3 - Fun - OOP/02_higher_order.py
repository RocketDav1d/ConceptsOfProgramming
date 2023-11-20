def mul(x, y):
    return x * y

def add1(x):
    return lambda a: a + x  # bind x to lambda => closure

def add(lhs : int, rhs: int):
    return add1(lhs)(rhs)  # x + y  # currying

incr = add1(1)

print(incr)  

print(incr(2))
print(incr(3))
print(incr(4))

















def accumulate(l : list, init : int, accu_func):
    res = init
    for element in l:
        res = accu_func(res, element)
    return res


def sum(l: list):
    return accumulate(l, 0, add)

def prod(l:list):
    # same as below without a named function
    return accumulate(l, 1, lambda a, b: a * b)
    #return accumulate(l, 1, mul)



l = [1, 2, 3, 4, 5, 6]
#print(f"sum = {sum(l)}, product = {prod(l)}")

def select(op):
    if op == '*':
        return prod
    return sum

op_inp = input("select operation (* or +)? ")
op = select(op_inp)
print(f" res of op {op_inp} is {op(l)}")




  
