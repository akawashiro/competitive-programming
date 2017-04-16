#! /bin/sh

i=1
while [ $i -lt 7 ]
do
	rm -r ~/$i
	i=`expr $i + 1`
done

