def check(string):
    return string.startswith("good ")

class CheckFailed(Exception):
    pass

class GoodInputString(str):
    def __init__(self, uncheckedInput):
        if not check(uncheckedInput):
            raise CheckFailed()
        self.value = uncheckedInput

def use(goodString : GoodInputString):
    if not goodString.startswith("good"):
        raise ValueError("Should never happen")

    print(goodString[4:], "is good!")

#------------------------

unchecked = ""
while unchecked != "quit":
    unchecked = input("Enter a string > ")
    try:
        #checked = GoodInputString(unchecked)
        use(unchecked)
    except CheckFailed:
        print("Try again!")

