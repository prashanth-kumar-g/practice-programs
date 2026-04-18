m, n = map(int, input("Enter the range(m & n) : ").split())

print("The palindrome numbers are :", end = " ")

num = m

while(num <= n):
    temp = num

    result = 0

    while(temp != 0):
        rem = temp % 10
        result = result * 10 + rem
        temp = temp // 10

    if(result == num):
        print(num, end = " ")

    num += 1
