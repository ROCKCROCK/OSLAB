echo "enter a positive no.:"
read n
t1=0
t2=1
nt=0
echo "Fibonacci Series> "
echo "$t1" 
echo "$t2"
nt=`expr $t1 + $t2`
while [ $nt -le $n ]
do
echo "$nt"
t1=$t2
t2=$nt
nt=`expr $t1 + $t2`
done




