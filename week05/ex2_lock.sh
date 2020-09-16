#!/bin/bash

if test ! -f file;
#if file exist then
then 
#write down 0 to th file
echo 0 > file
fi

if ln file file.lock
#if there is a file with name "fil.lock" then do the following
then
#touch file.lock
#make file.lock file
#100 times take the last element from the file
# and increment it after add to the same file
for i in {1..100}
do 
lastnum=$(tail -1 file)
((lastnum+=1))

echo $lastnum >> file
done
#remove file.lock file
rm file.lock
fi
