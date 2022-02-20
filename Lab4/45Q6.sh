echo "Enter Year: "
read y
a=`expr $y % 400`
b=`expr $y % 100`
c=`expr $y % 4`
if [ $a -eq 0 ] || [ $b -ne 0 ] && [ $c -eq 0 ]
then
echo "It is a Leap Year"
else
echo "It is not a Leap Year"
fi