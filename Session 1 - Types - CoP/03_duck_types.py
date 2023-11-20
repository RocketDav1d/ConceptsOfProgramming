
class Duck():
    def quack(self):
        print("Quack")
    def walk(self):
        print("waddle waddle")
    def really_a_duck(self):
        pass

def goDaisy(duck : Duck):
    duck.walk()
    duck.quack()
    duck.really_a_duck()

class Frog():
    def quack(self):
        print("Quaaaack")
    def walk(self):
        print("hop hop")

daisy = Duck()
kermit = Frog()

goDaisy(daisy)
goDaisy(kermit)
