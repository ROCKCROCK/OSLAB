echo "Enter the total number in array 1 ->"
read n1
echo "Enter number in array 1 ->"
i=0
while [ $i -lt $n1 ]
do
    read a1[$i]
    i=`expr $i + 1`
done
echo "Enter the total number in array 2 ->"
read n2
echo "Enter number in array 2 ->"
i=0
while [ $i -lt $n2 ]
do
    read a2[$i]
    i=`expr $i + 1`
done
j=0
for ((i = 0; i < n1; i++)) 
do
    a[j]=${a1[i]}
    j=`expr $j + 1`
done
for ((i = 0; i < n2; i++)) 
do
    a[j]=${a2[i]}
    j=`expr $j + 1`
done
echo "The merged array is : "
echo ${a[*]}