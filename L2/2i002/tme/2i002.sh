#!/bin/sh
# create an array with all the filer/dir inside ~/myDir
arr=(~/Documents/uni/L2/2i002/TME/S3/*.java)
first=(~/Documents/uni/L2/2i002/TME/S3/)
first=$((${#first}))
deuxpoints=(:)
nomcompterendu=(./CRc.txt)
> $nomcompterendu

# iterate through array using a counter
for ((i=0; i<${#arr[@]}; i++)); do
    #do something to each element of array
    two=$((${#arr[$i]}-$first))
    echo "${arr[$i]:$first:$two}:" >> $nomcompterendu
    cat ${arr[$i]} >> $nomcompterendu
    echo "\n" >> $nomcompterendu
done
