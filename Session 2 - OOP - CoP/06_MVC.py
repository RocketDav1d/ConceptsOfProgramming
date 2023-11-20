


class Model():
    def __init__(self, name = "unnamed"):
        self.__name = name

    def name(self):
        return self.__name

    def set_name(self, name):
        self.__name = name

class Controller():
    def __init__(self, model):
        self.model = model

    def change_name(self, name):
        self.model.set_name(name)

    def retrive_name(self):
        return self.model.name()

    
class View():
    def __init__(self, ctrl):
        self.ctrl = ctrl

    def input_name(self):
        name = input("Who are you? ")
        self.ctrl.change_name(name)

    def output_name(self):
        name = self.ctrl.retrive_name()
        print(f"hello {name}")


def main():
    model = Model()
    controller = Controller(model)
    view = View(controller)

    view.input_name()
    view.output_name()


if __name__ == "__main__":
    main()
