clear
echo enter a number
read num
echo TO REVERSE A NUMBER AND CHECK IF IT IS PALINDROME
echo "================================================"
echo the given number is : $num
original=$num
rev=0
while [ $num -gt 0 ]
do
rem=`expr $num % 10`
rev=`expr $rev \* 10 + $rem`
num=`expr $num / 10`
done
echo the reversed number is : $rev
if [ $original -eq $rev ]
then echo $original is a palindrome
else
echo $original is not a palindrome
fi
