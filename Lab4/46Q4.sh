echo "*****************************************"
echo "Calculate Electricity Charge"
echo "*****************************************"
echo "Enter the unit"

read unit
if [ $unit -gt 0 ] && [ $unit -le 50 ]

then
    charge=`expr $unit \* 50 / 100`

    echo $charge
elif [ $unit -gt 50 ] && [ $unit -le 150 ]

then
    charge=`expr 25 + $unit - 50 \* 75 / 100`

    echo "$charge"
elif [ $unit -gt 150 ] && [ $unit -le 250 ]
then
    charge=`expr 100 + $unit-150 \* 12 / 10`
echo "$charge"
elif [ $unit -gt 250 ]

then
    charge=`expr 100 + $unit-150 \* 120 / 100`
echo "$charge"  
fi
sur_charge=`expr $charge \* 2 / 10`
total_amt=`expr $charge + $sur_charge`
echo "*****************************************"
echo "Electricity Billing"
echo "*****************************************"
echo "Unit:$unit"
echo "charge:$total_amt"
echo "*****************************************"
