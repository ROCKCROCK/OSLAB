echo "Enter 1st number: "
read a
echo "Enter 2nd number: "
read b
if [ $a -eq $b ]
then
echo "The numbers are equal"
else
    if [ $a -gt $b ]
    then 
    echo "$a is the greatest and $b is the smallest"
    else
    echo "$b is the greatest and $a is the smallest"
    fi
fi
