clear
echo enter a number
read num
rem=`expr $num % 2`
if [ $rem -eq 0 ]
then
echo $num is EVEN
else
echo $num is ODD
fi
