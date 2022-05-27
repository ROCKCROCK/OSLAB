echo "Enter 1st Number For The Range->"
read n
echo "Enter 2nd Number For The Range->"
read n1
for (( i=$n; $i<=$n1; i++))
do
s=0
t=$i
l=$i
while [ "$l" != 0 ]
do
r=`expr $l % 10`
d=`expr $r \* $r \* $r`
s=`expr $s + $d`
l=`expr $l / 10`
done
if [ $t -eq $s ]
then
echo "Armstrong No. is->$t"
fi
done