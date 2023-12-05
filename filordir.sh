Write a shell script that displays a list of all the files in the current directory.

#!/bin/bash

echo "List of files in the current directory: "

for Documents in *; do
    echo $Documents
done
