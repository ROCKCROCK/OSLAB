echo "Enter total number->"
read n
echo "Enter Number->"
i=0
while [ $i -lt $n ]
do
read a[$i]
i=`expr $i + 1`
done
echo "In Reverse Order->"
while [ $n -gt 0 ]
do 
echo ${a[n-1]}
n=`expr $n - 1`
done

