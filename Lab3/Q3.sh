echo "Enter Number:"
read n
s=0
t=$n
while [ "$n" != 0 ]
do
r=`expr $n % 10`
s=`expr $s \* 10`
s=`expr $s + $r`
n=`expr $n / 10`
done
if [ $t -eq $s ]
then
echo "it is a pailndrome"
else
echo "it is not a pailndrome"
fi

