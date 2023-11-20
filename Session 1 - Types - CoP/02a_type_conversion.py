def use(p : int):
    pass

an_int = 42
a_float = 3.1415

res = an_int + a_float

use(res)

print("an_int  = {:>8} {}".format(an_int, type(an_int)))
print("a_float = {:>8} {}".format(a_float, type(a_float)))

print("res     = {:>8} {}".format(res, type(res)))