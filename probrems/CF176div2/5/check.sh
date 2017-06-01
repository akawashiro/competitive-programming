#! /bin/sh

printf "\n"

i=1
while [ -e checkInput$i.txt ]
do
	if [ ! -s checkInput$i.txt ] 
	then
		i=`expr $i + 1`
		continue
	fi
	./execution.out < checkInput$i.txt > checkOutput$i.txt
	printf "============================================\n"
	printf "check-$i\n"
	l=`cat checkOutput$i.txt | wc -l `
	c=`wc checkOutput$i.txt  -L | awk '{print $1}' `
	if [ $l -lt 100 ] && [ $c -lt 1000 ]
	then
		cat checkOutput$i.txt
	else
		printf "too long"
	fi
	printf "\n"
	i=`expr $i + 1`
done
printf "\n"

