from abc import ABC, abstractmethod



class LoggerInterface(ABC):
    @abstractmethod
    def log(self, message):
        pass



class Logger(LoggerInterface):
    def log(self, message):
        print(f"[LOG]: {message}")



class ServiceProvider:
    @staticmethod
    def provide_logger():
        return Logger()



class DIContainer:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(DIContainer, cls).__new__(cls)
            cls._instance._services = {}
        return cls._instance

    def register(self, key, provider):
        instance = provider()
        self._services[key] = instance

    def get(self, key):
        return self._services.get(key)



class Model:
    def __init__(self, name="", age=None, address=""):
        self._name = name
        self._age = age
        self._address = address

    def set_name(self, name):
        self._name = name

    def get_name(self):
        return self._name

    def set_age(self, age):
        self._age = age

    def get_age(self):
        return self._age

    def set_address(self, address):
        self._address = address

    def get_address(self):
        return self._address



class View:
    def display_person_info(self, name, age, address):
        print(f"Name: {name}")
        print(f"Age: {age}")
        print(f"Address: {address}")

    def ask_for_person_info(self):
        name = input("Please enter your name: ")
        age = input("Please enter your age: ")
        address = input("Please enter your address: ")
        return name, age, address



class Controller:
    def __init__(self, model, view, logger: LoggerInterface = None):
        self.model = model
        self.view = view
        self.logger = logger

    def set_person_info(self, name, age, address):
        self.model.set_name(name)
        self.model.set_age(age)
        self.model.set_address(address)
        self.logger.log(f"Person info set to Name: {name}, Age: {age}, Address: {address}")

    def display_person_info(self):
        name = self.model.get_name()
        age = self.model.get_age()
        address = self.model.get_address()
        self.view.display_person_info(name, age, address)

    def get_person_info_from_user(self):
        name, age, address = self.view.ask_for_person_info()
        self.set_person_info(name, age, address)



class Logger:
    def log(self, message):
        print(f"[LOG]: {message}")



def main():
    container = DIContainer()

    # Register our dependencies using service providers
    container.register('model', Model)
    container.register('view', View)
    container.register('logger', ServiceProvider.provide_logger)

    # Fetch dependencies to create the controller
    model = container.get('model')
    view = container.get('view')
    logger = container.get('logger')
    controller = Controller(model, view, logger)

    controller.get_person_info_from_user()
    controller.display_person_info()


if __name__ == "__main__":
    main()