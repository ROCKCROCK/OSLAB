echo "Enter Number->"
i=0
while [ $i -lt 10 ]
do
read a[$i]
i=`expr $i + 1`
done
echo "The entered array is ->"
echo ${a[@]}
for ((i = 0; i < 10; i++)) 
do
    for ((j = 0; j < 10-i-1; j++)) 
    do
        b=`expr $j + 1`
        if [ ${a[j]} -gt ${a[b]} ]
        then
            t=${a[j]}
            a[j]=${a[b]}
            a[b]=$t
        fi
    done
done
echo "The sorted array is ->"
echo ${a[*]}