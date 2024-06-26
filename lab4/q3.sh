#!/bin/bash

echo "Enter first number"
read num1
echo "Enter second number"
read num2

# Perform the operations
add=`expr $num1 + $num2`
sub=`expr $num1 - $num2`
mul=`expr $num1 \* $num2`

# Check if second number is not zero before division
if [ $num2 -ne 0 ]
then
    div=`expr $num1/$num2`
else
    div="Infinity"
fi

# Print the results
echo "Addition: $add"
echo "Subtraction: $sub"
echo "Multiplication: $mul"
echo "Division: $div"