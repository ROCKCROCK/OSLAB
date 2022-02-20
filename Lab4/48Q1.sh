echo "Enter your 7-Digit number->"
read num
lastDigit=0
while [ $num -gt 0 ]
do 
lastDigit=`expr $num % 10`
echo "$lastDigit"
num=`expr $num / 100`
done
