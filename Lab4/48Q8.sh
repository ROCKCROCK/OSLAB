echo "Enter the number n->"
read number
while [ $number -gt 0 ]
do
revNumber=0
loopCounter=$number
while [ $loopCounter -gt 0 ]
do
lastDigit=`expr $loopCounter % 10`
revNumber=`expr $revNumber + $lastDigit \* $lastDigit \* $lastDigit`
loopCounter=`expr $loopCounter / 10`
done 
if [ $number -eq $revNumber ]
then
echo "$number is Armstrong Number"
fi
number=`expr $number - 1`
done