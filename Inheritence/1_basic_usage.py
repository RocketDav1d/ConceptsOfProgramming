class Animal:
    def speak(self):
        print("Some generic sound")



class Dog(Animal):
    def speak(self):
        print("Woof! Woof!")


dog = Dog()
dog.speak()
