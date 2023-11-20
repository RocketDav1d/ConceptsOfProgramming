def goDaisy(duck):
    if not isinstance(duck, Duck):
        raise TypeError("Not a Duck")
    duck.walk()
    duck.quack()

class Duck():
    def quack(self):
        print("Quack")
    def walk(self):
        print("waddle waddle")

class EuropeanDuck(Duck):
    def quack(self):
        print("Euro Quack")
    def walk(self):
        print("Euro waddle waddle")


class Frog():
    def quack(self):
        print("Quaaaack")
    def walk(self):
        print("hop hop")

daisy = EuropeanDuck()
kermit = Frog()

goDaisy(daisy)
goDaisy(kermit)







# class EuropeanDuck(Duck):
#     def quack(self):
#         print("Euro Quack")
#     def walk(self):
#         print("Euro waddle waddle")
