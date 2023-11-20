class Animal:
    def __init__(self, species):
        self.species = species

    def make_sound(self):
        print("Some generic sound")



class Dog(Animal):
    def make_sound(self):
        print("Woof! Woof!")


dog = Dog("Canine")
dog.make_sound()  # Outputs: Woof! Woof!



class Dog(Animal):
    def __init__(self, species, breed):
        super().__init__(species)
        self.breed = breed







class Base:
    def __init__(self):
        print("Base init")

class Derived(Base):
    def __init__(self):
        super().__init__()
        print("Derived init")

obj = Derived()

# Outputs:
# Base init
# Derived init
