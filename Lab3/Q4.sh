echo "Enter 3 digit Number:"
read n
s=0
t=$n
while [ "$n" != 0 ]
do
r=`expr $n % 10`
d=`expr $r \* $r \* $r`
s=`expr $s + $d`
n=`expr $n / 10`
done
if [ $t -eq $s ]
then
echo "it is a armstrong"
else
echo "it is not a armstrong"
fi

