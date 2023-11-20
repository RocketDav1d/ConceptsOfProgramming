
class square():
    def __init__(self, edge_length):
        self.__edge_length = edge_length

    def set_length(self, edge_length):
        self.__edge_length = edge_length

    def area(self):
        return self.__edge_length * self.__edge_length


class rect(square):
    def __init__(self, width, height):
        self.__width = width
        self.__height = height

    def set_length(self, edge_length):
        self.__width = edge_length
        self.__height = edge_length

    def set_size(self, width, height):
        self.__width = width
        self.__height = height

    def area(self):
        return self.__width * self.__height





class Rectangle:
    def __init__(self, w, h):
        self.w = w
        self.h = h
    
    def set_width(self, w):
        self.w = w

    def set_height(self, h):
        self.h = h

class Square(Rectangle):
    def __init__(self, length):
        super().__init__(length, length)

def area(r : Rectangle): 
    return r.h * r.w

s = Square(5)
print(area(s))
















assert s.w == s.h, "Square is not square!" 

s.set_height(2)
print(area(s))
assert s.w == s.h, "Square is not square any more!"













    ## This fixes the invariants of the square 
    # def set_width(self, w):
    #     self.w = w
    #     self.h = w

    # def set_height(self, h):
    #     self.h = h
    #     self.w = h