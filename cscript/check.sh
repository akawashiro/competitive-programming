#! /bin/sh
g++ -std=c++11 source.cpp -Wall
if [ $? -eq 1 ]
then
    exit 1
fi

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
    #c=`wc output$i.txt  -L | awk '{print $1}' `
    #if [ $l -lt 100 ] && [ $c -lt 1000 ]
    if [ $l -lt 100 ]
    then
        cat output$i.txt
    else
        printf "too long"
    fi
    printf "\n"
    i=`expr $i + 1`
done
printf "\n"

