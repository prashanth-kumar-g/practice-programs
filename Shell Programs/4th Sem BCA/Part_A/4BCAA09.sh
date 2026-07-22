clear
echo the program name is : $0
if [ $# -lt 2 ]
then
echo number of arguments are insufficient!
echo please try again
exit 
fi
echo number of arguments : $#
echo first number : $1
echo second number : $2
sum=`echo "scale=2; $1 + $2" | bc`
echo ==================================
echo sum of 2 numbers using bc : $sum
echo
sum=`expr $1 + $2`
echo sum of 2 numbers using expr : $sum
echo ==================================
