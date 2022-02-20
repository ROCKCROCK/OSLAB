echo "Enter a number : "
read n
i=1
s=0
while [ $i -le $n ]
do
d=`expr $i \* $i`
s=`expr $s + $d`
i=`expr $i + 1`
done
echo "Sum of squares from 1 to $n = $s"