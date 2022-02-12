import cppclass

obj = cppclass.cppclass(123)

print(obj.get_value())

obj.set_value(456)

print(obj.get_value())
