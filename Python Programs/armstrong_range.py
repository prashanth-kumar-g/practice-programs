import math

m, n = map(int, input("Enter the range (m & n) : ").split())

print("The armstrong numbers are :", end = " ")

num = m

while(num <= n):
    temp = num

    if num == 0:
        total_digits = 1
    else:
        total_digits = int(math.log10(num)) + 1

    result = 0
    
    while(temp != 0):
        rem = temp % 10
        result = result + int(pow(rem, total_digits))
        temp = temp // 10

    if(result == num):
        print(num, end = " ")

    num += 1
