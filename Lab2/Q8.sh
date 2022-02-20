echo "Enter number: "
read a
if [ $a -lt 0 ]
then 
echo "The number is negative $a"
a=`expr $a \* $a`
echo "The square of number is $a"
else
echo "The number is positive"
a=`expr $a \* $a \* $a`
echo "The cube of number is $a"
fi
