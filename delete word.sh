echo "enter the file name:"
read file
echo "enter the word:"
read word
echo "file before deleting: "
cat $file
grep -v -i $word $file>t
mv t $file
echo "file after deleting"
cat $file
