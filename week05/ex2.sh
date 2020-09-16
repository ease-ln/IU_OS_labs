#!/bin/bash

if test ! -f file;
#if file exist then write down to the file 0
then
echo 0 > file
fi

for i in {1..100};
# from 100 times takes the last element from the file and increment it 
#by one and write to the "file"
do
	lastnum=`tail -1 file`
	lastnum=$((lastnum+1))

	echo $lastnum >> file
done
#As the result we have two same numbers one after other in file because 
#the the backgraund and foregraund threads takes the same number and add to it one.
