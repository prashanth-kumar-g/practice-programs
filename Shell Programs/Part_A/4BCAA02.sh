clear
tput cup 5 10
echo BANK INTEREST CALCULATION FORM
tput cup 6 10
echo ------------------------------
tput cup 8 10
echo 1.SIMPLE INTEREST
tput cup 10 10
echo 2.COMPOUND INTEREST
tput cup 12 10
echo 3.EXIT
tput cup 15 10
echo ENTER YOUR CHOICE
tput cup 15 30
read choice
clear
case $choice in
1)echo ENTER PRINCIPLE, TIME AND RATE
read p t r
si=`echo "scale=2; $p * $t * $r / 100" | bc`
echo PRINCIPLE = Rs.$p
echo TIME = $t years
echo RATE = $r%
echo SIMPLE INTEREST = Rs.$si;;
2)echo ENTER PRINCIPLE, TIME AND RATE
read p t r
amt=`echo "scale=2; $p * ( 1 + $r / 100 ) ^ $t" | bc`
ci=`echo "scale=2; $amt - $p" | bc`
echo PRINCIPLE = Rs.$p
echo TIME = $t years
echo RATE = $r%
echo COMPOUD INTEREST = Rs.$ci;;
3)exit;;
*)echo WRONG CHOICE
exit;;
esac
