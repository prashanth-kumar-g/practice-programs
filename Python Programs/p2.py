def helper(x,y):
	if x>y:
		return x
	else:
		return y

def main(a,b,c):
	return helper(helper(a,b),c)

a=int(input("Enter 1st number : "))
b=int(input("Enter 2nd number : "))
c=int(input("Enter 3rd number : "))

print("largest number = ",main(a,b,c))
