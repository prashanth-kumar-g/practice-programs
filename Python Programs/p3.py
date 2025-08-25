def sum_of_numbers(*args):
	sum=0
	for i in args:
		sum=sum+i
	return sum

def product_of_numbers(*args):
	product=1
	for i in args:
		product=product*i
	return product

numbers=map(int,input("Enter the numbers separated by space : ").split())
numbers=list(numbers)

print("sum = ",sum_of_numbers(*numbers))
print("product = ",product_of_numbers(*numbers))
