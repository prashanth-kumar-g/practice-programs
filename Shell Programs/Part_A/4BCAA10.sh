clear
echo "\nTo display files and their permissions"
echo ======================================
echo "\nfiles with read permission are : "
for file in *
do
if [ -f $file -a -r $file ]
then
echo $file
fi
done
echo "\nfiles with write permission are : "
for file in *
do
if [ -f $file -a -w $file ]
then
echo $file
fi
done
echo "\nfiles with execution permission are : "
for file in *
do
if [ -f $file -a -x $file ]
then
echo $file
fi
done
echo "\nfiles with read and write permission are : "
for file in *
do
if [ -f $file -a -r $file -a -w $file ]
then
echo $file
fi
done

