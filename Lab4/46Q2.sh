echo "Enter basic salary->"
read a
b=`expr $a \* 10 / 100`
c=`expr $a \* 15 / 100`
gs=`expr $a + $b + $c`
echo "Gross salary = $gs"