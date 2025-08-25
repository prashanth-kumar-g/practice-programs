clear
echo -n "enter a number : "
read n
fact=1
i=1
while [ $i -le $n ]
do
fact=`expr $fact \* $i`
i=`expr $i + 1`
done
echo factorial of $n is $fact
