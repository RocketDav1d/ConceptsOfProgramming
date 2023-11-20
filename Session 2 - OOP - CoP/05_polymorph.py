# class Animal:
#     def __init__(self, name):
#         self.name = name
     
#     def get_name(self):
#         return self.name

#     def speak(self):
#         raise NotImplementedError("Each animal should speak for themself")

# class Duck(Animal):
#     def speak(self):
#         print("Quack Quack")

# class Sheep(Animal):
#     def speak(self):
#         print("Määääähhhhh")

#--------------------------------------------------------------------------------------------------


# zoo = [Duck("Daisy"), Duck("Donald"), Sheep("Shaun"), Duck("Dagobert")]

# for animal in zoo:
#     animal.speak()


#--------------------------------------------------------------------------------------------------
# Defaults and code reuse
class Animal:
    def __init__(self, name):
        self.name = name
        
    def get_name(self):
        return self.name

    def speak(self):
        raise NotImplementedError("Each animal should speak for themself")

    def think(self):
        raise NotImplementedError("Each animal should think for themself")

    def _say(self, what):
        print(f"{self.name} makes: {what}")


class Duck(Animal):
    def speak(self):
        self._say("Quack Quack")

class Sheep(Animal):
    def speak(self):
        self._say("Määääähhhhh")
    
class Human(Animal):
    def speak(self):
        self._say("Cogito ergo sum!")

zoo = [Duck("Daisy"), Duck("Donald"), Sheep("Shaun"), Duck("Dagobert"), Human("Fabio")]

# for animal in zoo:
#     #animal.think()
#     animal.speak()
    


#--------------------------------------------------------------------------------------------------
# 
# def think(animal):
#     if isinstance(animal, Duck):
#         print("Swimming is great")
#         return 

#     if isinstance(animal, Sheep):
#         print("Meh, if I start counting I will fall asleep again.")
#         return

#     print("Can't think")   

# Pattern Matching
def think(animal):
    match animal:
        case Duck(name="Dagobert"):
            print("Money")
        case Duck():
            print("Swimming is great")
        case Sheep():
            print("Meh, if I start counting I will fall asleep again.")
        case _:
            print("Can't think")   




zoo = [Duck("Daisy"), Duck("Donald"), Sheep("Shaun"), Duck("Dagobert")]
zoo.append(Human("Fabio"))

for animal in zoo:
    think(animal)
    animal.speak()





































# class Animal:
#     def __init__(self, name):
#         self.name = name
        
#     def get_name(self):
#         return self.name

#     def speak(self):
#         raise NotImplementedError("Each animal should know how to speak")

#     def _say(self, what):
#         print(f"{self.name} makes: {what}")


# class Duck(Animal):
#     def speak(self):
#         self._say("Quack Quack")


# class Sheep(Animal):
#     def speak(self):
#         self._say("Määääähhhhh")
    





















# def think(animal):
#     match animal:
#         case Duck(name="Dagobert"):
#             print("I need to count my money")

#         case Duck():
#             print("Swimming is great")
#         case Sheep():
#             print("Meh, if I start counting I will fall asleep again.")
#         case _:
#             print("Can't think")   

