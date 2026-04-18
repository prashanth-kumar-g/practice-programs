import math

n = int(input("Enter the no. of terms : "))

print("The armstrong numbers are :", end = " ")

num = 0
count = 0

while(count != n):
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
        count += 1

    num += 1
