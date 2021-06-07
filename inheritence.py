#single inheritene
class A:
    def __init__(self,a):
        print("A")
        self.a = a

class B(A):
    def __init__(self, a):
        A.__init__(self,a)
        print("B")

ob =B("Simran")

#multiple inheritence
class C:
    def __init__(self):
        self.str1 = "Simran"
        print("c")

class D:
    def __init__(self):
        self.str2 ="Priya"
        print("d")

class E(C,D):
    def __init__(self):
        C.__init__(self)
        D.__init__(self)
        print("E")

    def process(self):
        print(self.str1,self.str2)

ob = E()
ob.process()

#mutilevel inheritence
class F:
    def __init__(self):
        print("F")
        self.str3 = "ED"

class G(F):
    def __init__(self):
        F.__init__(self)
        print("G")
        self.str4 = "FG"

class H(G):
    def __init__(self):
        G.__init__(self)
        print("H")

    def process(self):
        print(self.str3,self.str4)

ob = H()
ob.process()