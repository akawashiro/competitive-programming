#! /bin/sh
# 普段は1個しかディレクトリを削除しません

i=1
while [ $i -le 1 ]
do
	rm -r ~/$i
	i=$((i+1))
done

