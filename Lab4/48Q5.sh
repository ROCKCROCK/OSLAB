echo "Write a number->"
read num
temp=$num
rev=0
sum=0
while [ $temp -gt 0 ]
do
lastDigit=`expr $temp % 10`
rev=`expr $rev \* 10 + $lastDigit`
sum=`expr $sum + $lastDigit`
temp=`expr $temp / 10`
done
echo "Reverse number is $rev"
echo "Sum of Digits is $sum"
