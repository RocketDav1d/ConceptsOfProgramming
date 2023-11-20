class Animal:
    def speak(self):
        print("Some generic sound")



class Cat(Animal):
    def speak(self):
        super().speak()
        print("Meow! Meow!")


cat = Cat()
cat.speak()


#----------------------------


class Base:
    def __init__(self):
        print("Base init")

class Derived(Base):
    def __init__(self):
        super().__init__()
        print("Derived init")

obj = Derived()
print(obj)
