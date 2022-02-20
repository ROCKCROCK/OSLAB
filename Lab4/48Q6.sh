echo "Enter a Number n -> "
read a
while [ $a -gt 0 ]
do
sum=0
num=$a
while [ $num -gt 0 ]
do
d=`expr $num % 10`
sum=`expr $sum \* 10 + $d`
num=`expr $num / 10`
done
if [ $sum -eq $a ]
then
echo "$a is Palindrome Number"

fi
a=`expr $a - 1`
done