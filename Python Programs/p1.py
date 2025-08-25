def outer_func(a,b):
	def inner_func():
		return a+b
	result=inner_func()
	return result+5

a=int(input("Enter value of a : "))
b=int(input("Enter value of b : "))

print(f"{a} + {b} + 5 = {outer_func(a,b)}")
