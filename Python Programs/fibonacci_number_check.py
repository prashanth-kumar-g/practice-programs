n = int(input("Enter a number : "))

f1 =  0
f2 = 1

flag = False

while(f1 <= n):
    if(f1 == n):
        flag = True

    fn = f1 + f2
    f1 = f2
    f2 = fn

if(flag):
    print(n, " is a fibonnaci number")
else:
    print(n, " is not a fibonacci number")
