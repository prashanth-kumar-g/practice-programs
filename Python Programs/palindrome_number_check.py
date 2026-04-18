n = int(input("Enter a number : "))

m = n
rev = 0

while(m != 0):
    rem = m % 10
    rev = rev * 10 + rem
    m = m // 10

print("The reversed number is : ", rev)

if(n == rev):
    print(n, " is a palindrome number")
else:
    print(n, " is not a palindrome number")
