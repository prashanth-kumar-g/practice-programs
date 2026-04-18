m, n = map(int, input("Enter the range (m & n) : ").split())

f1 = 0
f2 = 1

while(f1 < m):
    fn = f1 + f2
    f1 = f2
    f2 = fn

print("The fibonacci numbers are :", end = " ")

while(f1 <= n):
    print(f1, end = " ")
    fn = f1 + f2
    f1 = f2
    f2 = fn
