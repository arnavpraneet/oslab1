#!/bin/bash

# Check if one argument is passed
echo "Enter a positive integer: "
read num
# Check if the argument is a positive integer
if ! [[ $num =~ ^[0-9]+$ ]]
then
        echo "Please provide a positive integer."
        exit 1
fi

# Assign the argument to a variable


# Calculate the factorial
factorial=1
for (( i=1; i<=num; i++ ))
do
    factorial=$((factorial * i))
done

# Print the result
echo "The factorial of $num is $factorial."