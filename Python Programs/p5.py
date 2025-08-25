def fact(n):
	fact=1
	for i in range(1,n+1,1):
		fact=fact*i
	return fact

def fib(num):
	series=[]
	f1=0
	f2=1
	for i in range(0,num,1):
		series.append(f1)
		temp=f1
		f1=f2
		f2=temp+f2
	return series

while True:
	print("*"*60)
	print("  1) Compute Factorial   2) Print Fibonacci Series  3) Exit  ")
	print("*"*60)
	choice=int(input("Enter your choice : "))
	if choice==1:
		num=int(input("Enter a number for finding factorial : "))
		print(f"Factorial of {num} = {fact(num)}")
	elif choice==2:
		num=int(input("Enter the number of terms for fibonacci series : "))
		print(f"The fibonacci series are : {fib(num)}")
	elif choice==3:
		print("Exiting...")
		break
	else:
		print("Invalid Choice, Enter Again.")
