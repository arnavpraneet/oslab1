echo "Enter filename";
read name;
gcc $name.c -o $name && ./$name;
