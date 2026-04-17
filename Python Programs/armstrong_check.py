import math

n = int(input("Enter a number : "))

total_digits = int(math.log10(n)) + 1

m = n
num = 0

while(m != 0):
    rem = m % 10
    num = num + pow(rem, total_digits)
    m = m // 10

if(num == n):
    print(n, " is a armstrong number")
else:
    print(n, " is not a armstrong number")
