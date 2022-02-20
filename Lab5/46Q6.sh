echo "Enter total number->"
read n
echo "Enter Number->"
i=0
j=0
while [ $i -lt $n ]
do
read a[$i]
i=`expr $i + 1`
done
max=${a[0]}
min=${a[0]}
while [ $j -lt $n ]
do
if [ ${a[j]} -gt $max ]
then
max=${a[j]}
fi
if [ ${a[j]} -lt $min ]
then
min=${a[j]}
fi
j=`expr $j + 1`
done
echo " Maximum in array->$max"
echo " Minimum in array->$min"