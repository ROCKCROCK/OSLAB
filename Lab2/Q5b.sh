echo "enter 1st no.->"
read a
echo "enter 2nd no.->"
read b
val=`expr $a + $b`
a1=`expr $val - $a`
b1=`expr $val - $b`
echo "1st no.-> $a1 2nd no.-> $b1"
