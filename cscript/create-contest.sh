#! /bin/sh

i=1
p=`dirname $0`
while [ $i -lt 7 ]
do
	mkdir ~/${i}
	cp "${p}/build.sh" ~/$i/build.sh
	cp "${p}/check.sh" ~/$i/check.sh
	cp "${p}/judge.sh" ~/$i/judge.sh
	cp "${p}/test.sh" ~/$i/test.sh
	chmod +x ~/$i/build.sh
	chmod +x ~/$i/check.sh
	chmod +x ~/$i/judge.sh
    chmod +x ~/$i/test.sh
	touch ~/$i/source.cpp
	cp ~/clib/TemplateForICPC.cpp ~/$i/source.cpp
	j=1
	while [ $j -lt 6 ]
	do
		touch ~/$i/input$j.txt
		j=`expr $j + 1`
	done
	i=`expr $i + 1`
done

