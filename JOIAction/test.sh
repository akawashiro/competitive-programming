#! /bin/sh

i=1
((i=i+1))
echo $i

while ((i<10))
do
	echo $i
	((i=i+1))
done
