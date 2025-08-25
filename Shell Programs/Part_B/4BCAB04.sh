clear
f1=0
f2=1
echo "How many numbers"
read n
f3=`expr $f1 + $f2`
i=3
echo fibbonacci series are
echo -n "$f1 $f2 "
while [ $i -le $n ]
do
echo -n "$f3 " 
f1=$f2
f2=$f3
f3=`expr $f1 + $f2`
i=`expr $i + 1`
done
echo 
