echo "Enter the range num1 ->"
read num1 
echo "Enter the range num2 ->"
read num2
echo "Given range from user is $num1 and $num2 "
echo "Prime Numbers are:"
while [ $num1 -le $num2 ]
do
i=2
flag=1
while [ $i -lt $num1 ]
    do
        if [ `expr $num1 % $i` -eq 0 ]
        then
            flag=0
            break
        else
            i=`expr $i + 1`
        fi
    done
    if [ $flag -eq 1 ]
    then
        echo $num1
    fi
    num1=`expr $num1 + 1`
done
