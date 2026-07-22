# Creating directories and transferring files
clear
echo
echo "          ========================="
echo "          CREATING AND MOVING FILES"
echo "          ========================="
echo
echo
echo CREATING FIRST DIRECTORY AND STORING 5 FILES
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo
echo Enter first directory name
read dir1
mkdir $dir1
echo Directory $dir1 created succesfully
cd $dir1
touch f1 f2 f3 f4 f5
echo $dir1 contains
ls
cd ..
echo
echo
echo CREATING SECOND DIRECTORY
echo "~~~~~~~~~~~~~~~~~~~~~~~~~"
echo
echo Enter second directory name
read dir2
mkdir $dir2
echo Directory $dir2 created successfully
cd $dir1
mv f1 f2 f3 f4 f5 /home/system/Documents/Programs/Part_B/$dir2
echo Files f1 f2 f3 f4 f5 successfully moved from $dir1 to $dir2
cd ..
cd $dir2
echo
echo
echo AFTER TRANSFERRING FILES FROM $dir1, $dir2 NOW CONTAINS
echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
echo
ls
cd ..
cd $dir1
echo
echo
echo $dir1 IS NOW EMPTY
echo "~~~~~~~~~~~~~~~~~"
echo
cd ..
rm -r $dir1 $dir2     # Remove newly created directories dir1 & dir2
