#!/bin/bash

echo "Enter first number: "
read num1
echo "Enter second number: "
read num2
echo "Enter third number: "
read num3


# Find the largest number
if [ $num1 -gt $num2 ] && [ $num1 -gt $num3 ]
then
    echo "$num1 is the largest number."
elif [ $num2 -gt $num1 ] && [ $num2 -gt $num3 ]
then
    echo "$num2 is the largest number."
else
    echo "$num3 is the largest number."
fi