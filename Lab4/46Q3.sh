echo "Enter Number->"
read a
s=0
n=$a
i=3
while [ $i -gt 0 ]
do
b=`expr $n % 10`
s=`expr $s + $b \* $b`
n=`expr $n / 10`
i=`expr $i - 1` 
done
echo "Sum of square of last 3 digit -> $s"