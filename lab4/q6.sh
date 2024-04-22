#!/bin/bash

# Check if one argument is passed
echo "Enter a number"
read num

# Print the multiplication table
for (( i=1; i<=10; i++ ))
do
    echo "$num * $i = $((num * i))"
done