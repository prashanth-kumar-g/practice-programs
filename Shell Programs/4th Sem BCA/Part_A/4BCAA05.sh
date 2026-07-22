clear
echo "\nenter number of records : "
tput cup 1 26
read n
i=1
t=0
while [ $i -le $n ]
do
echo "\nenter student number (4 digits) : "
tput cup `expr 3 + $t` 34
read num
echo "enter student name : "
tput cup `expr 4 + $t` 21
read name
echo "enter student age : "
tput cup `expr 5 + $t` 20
read age
echo "enter student sex (m/f) : "
tput cup `expr 6 + $t` 26
read sex
echo "enter student height (cm) : "
tput cup `expr 7 + $t` 28
read ht
echo "enter student weight (kg) : "
tput cup `expr 8 + $t` 28
read wt
t=`expr $t + 7`
echo "$num  |  $name  |  $age  |  $sex  |  $ht  |  $wt" >> stdlist
i=`expr $i + 1`
done
echo "\n****************STUDENT INFORMATION****************\n"
printf "Reg No.    Name     Age    Sex    Height    Weight\n"
echo "==================================================="
awk -F "|" '{printf("%-8d %-10s %-4d %-8s %-9d %-8d \n", $1, $2, $3, $4, $5, $6)}' stdlist
echo "===================================================\n"  
