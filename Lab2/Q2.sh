echo "Enter Sec:"
read sec
val=`expr $sec % 60`
val1=`expr $sec / 60`
val2=`expr $val1 % 60`
val3=`expr $val1 / 60`
echo "hours:minute:sec:> $val3:$val2:$val"
