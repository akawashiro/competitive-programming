#! /bin/sh

i=1
while [ $i -le 6 ]
do
	if [ ! -s actionInput$i.txt ] || [ ! -e actionInput$i.txt ]
	then
		i=$(($i+1))
		continue
	fi

	./execution.out < actionInput$i.txt > actionOutput$i.txt
	printf "============================================\n"
	printf "action-$i\n"
	l=`cat actionOutput$i.txt | wc -l `
	c=`wc actionOutput$i.txt  -L | awk '{print $1}' `
	if [ $l -le 100 ] && [ $c -le 1000 ]
	then
		cat actionOutput$i.txt
	else
		printf "too long"
	fi
	printf "\n"

	i=$(($i+1))
done

