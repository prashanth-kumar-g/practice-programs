#file permissions
clear
echo "#################################################################################################"
echo "\n***************************************************************************"
echo `pwd` contents
ls -l
echo
echo =====================================
echo CHANGING PERMISSIONS IN SYMBOLIC MODE
echo =====================================
echo -n "Enter the file name : "
read fname1
echo -n "Enter the type (u/g/o) : "
read type
echo -n "Enter one of the permissions (r/w/x or -r/-w/-x) : "
read perm
chmod $type+$perm $fname1
echo "\nAFTER CHANGING PERMISSIONS"
ls -l $fname1
echo "***************************************************************************"
echo
echo "***************************************************************************"
echo `pwd` contents
ls -l
echo
echo =====================================
echo CHANGING PERMISSIONS IN ABSOLUTE MODE
echo =====================================
echo -n "Enter the file name : "
read fname2
echo -n "Enter permission to be changed (755 format) : "
read perm
chmod $perm $fname2
echo "\nAFTER CHANGING PERMISSIONS"
ls -l $fname2
echo "***************************************************************************\n"
echo "#################################################################################################"
##########
