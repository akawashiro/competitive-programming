#! /bin/sh

printf "\n"

i=1
while [ -e input$i.txt ]
do
	if [ ! -s input$i.txt ]
	then
		i=`expr $i + 1`
		continue
	fi
	./execution.out < input$i.txt > output$i.txt
	printf "============================================\n"
	printf "check-$i\n"
	l=`cat output$i.txt | wc -l `
	c=`wc output$i.txt  -L | awk '{print $1}' `
	printf "\n"
	i=`expr $i + 1`
done
printf "\n"
