echo "Enter the number: "
read n
n=`expr $n % 2`
if [ $n -eq 0 ]
then
  echo "Entered number is even."
else
  echo "Entered number is odd."
fi