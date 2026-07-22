clear
sum=0
echo enter a number
read num
n=$num
while [ $num -gt 0 ]
do
rem=`expr $num % 10`
sum=`expr $sum + $rem`
num=`expr $num / 10`
done
echo the sum of digits in $n is $sum
