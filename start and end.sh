echo "enter the file name:"
read name
echo "enter the starting line:"
read startline
echo "enter the ending line:"
read endline
sed -n $startline,$endline\p $name
