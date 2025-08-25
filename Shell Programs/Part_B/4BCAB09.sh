# TO COMPRESS FILES
clear
echo "     ======================"
echo "        FILE COMPRESSION"
echo "     ======================"
echo
echo ENTER FILENAME TO BE COMPRESSED
echo -------------------------------
echo
read f
echo
echo BEFORE ZIPPING FILE SIZE IS 
echo ---------------------------
wc -c $f
gzip $f
echo
echo COMPRESSION RESULTS USING 'gzip'
echo ------------------------------
gzip -l $f.gz
echo
echo UNZIPPING USING 'gunzip'
echo ----------------------
gunzip $f.gz      # or gunzip $f
echo AFTER UNZIPPING FILE SIZE IS
echo ----------------------------
wc -c $f
