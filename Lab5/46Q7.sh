echo "Enter total number->"
read n
echo "Enter Number->"
i=0
while [ $i -lt $n ]
do
read a[$i]
i=`expr $i + 1`
done
echo "Enter the element -> "
read e
for((i=1;i<=$n;i++))
do
if [ ${a[i]} -eq $e ]
then
echo "$e found at index $i"
break
fi
done
