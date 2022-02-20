echo "enter a three digit no.:>"
read num
a=`expr $num % 10`
val=`expr $num / 10`
b=`expr $val % 10`
val1=`expr $val / 10`
sum=`expr $a + $b + $val1`
echo "sum is:> $sum"


