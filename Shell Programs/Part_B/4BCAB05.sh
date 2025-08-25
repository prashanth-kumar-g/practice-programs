clear
echo enter a string
read str
len=`echo $str | wc -c`
len=`expr $len - 1`
echo "***************************************"
echo "Original string is : $str"
echo "Length of string is : $len"
echo -n "Reversed string is : "
while [ $len -ge 1 ]
do
rev=`echo $str | cut -c $len`
echo -n $rev
len=`expr $len - 1`
done
echo 
echo "***************************************"
