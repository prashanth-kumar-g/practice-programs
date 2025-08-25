clear
echo enter a string
read str
len=`expr length $str`
i=1
count=0
while [ $i -le $len ]
do
ch=`echo $str | cut -c $i`
case $ch in
[aeiouAEIOU]) count=`expr $count + 1`;;
esac
i=`expr $i + 1`
done
echo the given string is $str
echo the number of vowels in string is $count 
