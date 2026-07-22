clear
echo how many entries
read n
i=1
echo "\nenter the first number : "
read num1
max=$num1
min=$num1
echo enter `expr $n - 1` numbers : 
while [ $i -lt $n ]
do
read num
if [ $num -gt $max ]
then max=$num
fi
if [ $num -lt $min ]
then min=$num
fi
i=`expr $i + 1`
done
echo maximum value = $max
echo minimum value = $min
