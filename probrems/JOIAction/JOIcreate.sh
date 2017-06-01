#! /bin/sh
# 普段は1個しかディレクトリを生成しません

i=1
while [ $i -le 1 ]
do
	mkdir ~/${i}
	cp ./build.sh ~/$i/build.sh
	cp ./check.sh ~/$i/check.sh
	cp ./action.sh ~/$i/action.sh
	chmod +x ~/$i/build.sh
	chmod +x ~/$i/check.sh
	chmod +x ~/$i/action.sh
	touch ~/$i/source.cpp
	j=1
#普段は３個しかテストケースがありません
	while [ $j -le 3 ]
	do
		touch ~/$i/checkInput$j.txt
		touch ~/$i/actionInput$j.txt
		j=$((${j}+1))
	done
	i=$((${i}+1))
done

