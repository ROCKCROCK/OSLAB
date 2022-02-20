echo "Total Number of eLements->" 
read n
echo "Enter the elements->" 
for  ((i  =  0;  i  <  n;  i++))
do
read arr[i]
done
echo "Array-> " 
echo ${arr[*]}
echo "Enter Index-> " 
read loc
echo "Enter your choice : 1)Insert 2)Delete " 
read ch
case $ch in
1) echo  "Enter the new element ->" 
read no
for ((i=n;i>loc;i--)) 
do
arr[i]=${arr[i-1]}
done
arr[loc]=$no
;;
2) for ((i=loc;i<n;i++)) 
do
arr[i]=${arr[i+1]}
done 
n=`expr $n - 1`
;;
*) echo "Wrong choice !"
;; 
esac
echo "The New array is -> " 
echo ${arr[*]}
