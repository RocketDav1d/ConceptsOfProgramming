import math

def growup(child: str):
    child = "I am now a responsible adult"
    return child

print("\n--[immutable]------------------\n")
peter = "I will never grow up"
print("Peter:", peter)
growup(peter)
print("Peter:", peter)





print("\n--[ Rebind ]------------------\n")
pan = peter 
print("Pan:", pan)

peter = growup(peter)
print("Peter:", peter)
print("Pan:", pan)



print("\n--[ State ]------------------\n")
def grow(l: list):
    for _ in range(len(l)): l.pop(0)
    l.extend(["I", "am", "now", "a", "responsible", "adult"])

peter = ["I", "will", "never", "grow", "up"]
pan = peter 
print(peter)
grow(peter)
print("Peter:", peter)
print("Pan:", pan)

