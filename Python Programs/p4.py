def fib(n):
	if n==0:
		return 0
	elif n==1:
		return 1
	else:
		return fib(n-1)+fib(n-2)

num=int(input("Enter the number of terms : "))

print("The fibonacci series are :  ",end="")
for i in range(0,num+1,1):
	print(fib(i),end="  ")
print()
