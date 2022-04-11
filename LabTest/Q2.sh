echo "Enter 1st side of triangle-> "
read a
echo "Enter 2nd side of triangle-> "
read b
echo "Enter 3rd side of triangle-> "
read c

d=`expr $a \* $a`
e=`expr $b \* $b`
f=`expr $c \* $c`

g=`expr $d + $e`
h=`expr $e + $f`
i=`expr $f + $d`

if [ $g -eq $f -o $h -eq $d -o $i -eq $e ]
then 
echo "It is a right angle triangle!!:)"
else
echo "It is not a right angle triangle!!:)"
fi