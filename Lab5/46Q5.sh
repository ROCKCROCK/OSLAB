echo "Enter Number->"
i=0
while [ $i -lt 10 ]
do
read a[$i]
i=`expr $i + 1`
done
echo "array is -> ${a[@]}"