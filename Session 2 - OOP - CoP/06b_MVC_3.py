class Config():
    def __init__(self, doTrace = True):
        self.ask = "How do you want to be called? "
        self.greet = "Good to see you {}."
        self.trace = doTrace
NO_TRACE = False

NEWLINE = '\n'
class Logger():
    
    def __init__(self, config):
        self.logs = []
        self.do_trace = config.trace

    def trace(self, msg):
        if self.do_trace:
            self.logs.append(f"[trace] {msg}")

    def info(self, msg):
        self.logs.append(f"[info] {msg}")

    def dump(self):
        print(f"-------------------\nLogs:\n{NEWLINE.join(self.logs)}\n-------------------")


class Model():
    def __init__(self, log, name = "unnamed"):
        self.__name = name
        self.log = log

    def name(self):
        self.log.trace("Model.name()")
        return self.__name

    def set_name(self, name):
        self.log.trace(f"Model.set_name({name})")
        self.__name = name

class Controller():
    def __init__(self, model, log):
        self.model = model
        self.log = log

    def change_name(self, name):
        self.log.trace(f"Controller.change_name({name})")
        self.log.info(f"Change name from {self.model.name()} to {name}")
        self.model.set_name(name)

    def retrive_name(self):
        self.log.trace(f"Controller.retrive_name()")
        return self.model.name()

    
class View():
    def __init__(self, ctrl : Controller, config, log):
        self.ctrl = ctrl
        self.conf = config
        self.log = log

    def input_name(self):
        self.log.trace(f"View.input_name()")
        name = input(self.conf.ask)
        self.ctrl.change_name(name)

    def output_name(self):
        self.log.trace(f"View.output_name()")
        name = self.ctrl.retrive_name()
        print(self.conf.greet.format(name))


def main():
    #config = Config(NO_TRACE)
    config = Config() 
    log = Logger(config)
    
    model = Model(log)
    controller = Controller(model, log)
    view = View(controller, config, log)

    view.input_name()
    view.output_name()

    log.dump()

if __name__ == "__main__":
    main()
