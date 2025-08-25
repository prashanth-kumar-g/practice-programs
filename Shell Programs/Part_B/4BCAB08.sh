# Program to wish good morning, good afternoon etc depending on the system time
temphr=`date | cut -c 12-13`
dat=`date +"%a %d %h of %Y (%r)"`
echo date = $dat
if [ $temphr -lt 12 ]
then
mesg="Good Morning $LOGNAME, Have nice day!"
fi
if [ $temphr -gt 12 -a $temphr -le 16 ]
then
mesg="Good Afternoon $LOGNAME !!"
fi
if [ $temphr -gt 16 -a $temphr -le 18 ]
then
mesg="Good Evening $LOGNAME !!"
fi
echo $mesg
