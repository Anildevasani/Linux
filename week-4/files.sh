write a shell script that list the all files in a directory

#!/bin/bash

echo "List of files in the directory: "

for file in *; do
    echo $file
done
