class A:
    def hello(self):
        print("Hello from A")

class B(A):
    def hello(self):
        super().hello()
        print("Hello from B")

class C(A):
    def hello(self):
        super().hello()
        print("Hello from C")

class D(B, C):
    def hello(self):
        super().hello()

obj = D()
obj.hello()


print(D.mro())
