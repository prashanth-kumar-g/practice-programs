#patter search
clear 
echo
echo ===================================
echo SEARCHIG PATTERN IN THE GIVEN FILES
echo ===================================
echo
echo Enter first filename
read file1
echo Enter names and press ctrl+d
cat > $file1
echo
echo Enter second filename
read file2
echo Enter names and press ctrl+d
cat > $file2
clear
echo file1 contents
cat $file1
echo "\n"
echo file2 contents
cat $file2
echo
echo Enter the name to be searched - Using grep command
read name
grep -n "$name" $file1 $file2
echo Searching for a fixed string - Using fgrep command
fgrep -n "Lilly" $file1 $file2
