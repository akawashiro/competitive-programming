#! /bin/sh

printf "\n"

i=1
while [ -e ci$i.txt ]
do
	if [ ! -s ci$i.txt ] 
	then
		i=$(($i+1))
		continue
	fi
	./execution.out < ci$i.txt > co$i.txt
	printf "============================================\n"
	printf "check-$i\n"
	l=`cat co$i.txt | wc -l `
	c=`wc co$i.txt  -L | awk '{print $1}' `
	if [ $l -le 100 ] && [ $c -le 1000 ]
	then
		cat co$i.txt
	else
		printf "too long"
	fi
	printf "\n"
	i=$(($i+1))
done
printf "\n"

