echo "Something";
read a, b;
expr `&a + &b`;
expr `&a /* &b`; # division
if(a -gt b) # -gt -lt -eq -ge -le
	echo "A is greater";
else
	echo "B is greater";
fi

