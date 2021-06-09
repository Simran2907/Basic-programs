class A(object):
    def __init__(self):
       self._name = None
       self.age = 0
    def get_attribute(self):
        print("IN GETTER")
        return(self._name)

    def set_attribute(self,x):
        print("IN SETTER")
        self._name = x
    def delete_attribute(self):
        print("Delete")
        del self._name

    name = property(get_attribute,set_attribute,delete_attribute)

ob = A()
ob.name = "Simran"
print(ob.name)

