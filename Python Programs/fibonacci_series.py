n = int(input("Enter the no. of terms : "))

print("The fibonacci numbers are :", end = " ")

f1 = 0
f2 = 1

for i in range(1, n + 1):
    print(f1, end = " ")
    fn = f1 + f2
    f1 = f2
    f2 = fn
