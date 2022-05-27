echo "Enter the range num1->"
read a1 
echo "Enter the range num2->"
read a2
echo "Given range from user is $a1 and $a2 "
echo "Prime Numbers are:"
while [ $a1 -le $a2 ]
do
i=2 
f=1
while [ $i -lt $a1 ]
    do
        if [ `expr $a1 % $i` -eq 0 ]
        then
            f=0
            break
        else
            i=`expr $i + 1`
        fi
    done
    if [ $f -eq 1 ]
    then
        echo $a1
    fi
    a1=`expr $a1 + 1`
done