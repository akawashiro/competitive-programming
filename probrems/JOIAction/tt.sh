i=1
while ((i < 6))
do
	touch "testInput${i}.txt"
	printf "test${i}\n" > "testInput${i}.txt"
	((i++))
done

