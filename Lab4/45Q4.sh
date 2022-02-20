echo "Enter the 1st number:"
read a
echo "Enter the 2nd number:"
read b
echo "Enter the 3rd number:"
read c
if [ $a -ge $b ] && [ $a -ge $c ]
then
echo "Greatest number is>"
echo $a
if [ $b -ge $a ] && [ $b -ge $c ]
then 
echo "Greatest number is>"
echo $b
fi
else 
echo "Greatest number is>"
echo $c
fi