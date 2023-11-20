def in_a_galaxy_far_far_away(x):
    x.public = 42
    x.__private = 13
    print (x._Test__private)

    x._Test__private = 13373
    print ("far far away: ", x.get_values())

    return



class Test():
    def __init__(self, pub, priv):
        self.public = pub
        self.__private = priv

    def get_values(self):
        return (self.public, self.__private)


a = Test(5, 10)

print ("Values:", a.get_values())
print ("public:", a.public)

# Accessing it will be prevented by python
#print ("private:", a.__private)

in_a_galaxy_far_far_away(a)

print ("Back form far far away: ", a.get_values())
print ("private:", a.__private)
















# You can still access it if you really try
#print (a._Test__private)

#x._Test__private = 13373





