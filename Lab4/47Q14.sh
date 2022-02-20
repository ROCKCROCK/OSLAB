echo "Enter Hours->"
read h
overtime=`expr $h - 8`
pay=15
if [ $overtime -gt 0 ]
then
amt=`expr $overtime \* $pay`
echo "Overtime Payment: $amt"
else
echo "No Overtime"
fi