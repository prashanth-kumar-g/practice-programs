n = int(input("Enter the no. of terms : "))

print("The palindrome numbers are :", end = " ")

num = 0
count = 0

while(count != n):
    temp = num

    result = 0

    while(temp != 0):
        rem = temp % 10
        result = result * 10 + rem
        temp = temp // 10

    if(result == num):
        print(num, end = " ")
        count += 1

    num += 1
