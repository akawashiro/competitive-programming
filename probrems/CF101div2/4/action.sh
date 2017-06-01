#! /bin/sh

i=1
while [ $i -le 6 ]
do
	if [ ! -s ai$i.txt ] || [ ! -e ai$i.txt ]
	then
		i=$(($i+1))
		continue
	fi

	./execution.out < ai$i.txt > ao$i.txt
	printf "============================================\n"
	printf "action-$i\n"
	l=`cat ao$i.txt | wc -l `
	c=`wc ao$i.txt  -L | awk '{print $1}' `
	if [ $l -le 100 ] && [ $c -le 1000 ]
	then
		cat ao$i.txt
	else
		printf "too long"
	fi
	printf "\n"

	i=$(($i+1))
done

