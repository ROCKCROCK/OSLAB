a=10
b=5
val=`expr $a + $b`
echo "a+b=$val"
val=`expr $a - $b`
echo "a-b=$val"
val=`expr $a \* $b`
echo "a*b=$val"
val=`expr $a / $b`
echo "a/b=$val"
val=`expr $a % $b`
echo "a%b=$val"