#!/bin/bash

# REFERENCE:
# https://www.runoob.com/linux/linux-comm-awk.html

if [ $# -ne 0 ]; then # $# is the number of arguments
  echo "Usage: $0"
  exit 1
fi

tmp_file=tmp.txt # No space here !!

# if the file already exists, remove it
if [ -f $tmp_file ]; then
  echo "$tmp_file already exists, delete it? (y/n)"
  while read -s -n1 yn; do
    if test $yn = n -o $yn = N; then # Notice the spaces near "=" !!
      echo "$tmp_file is not deleted, exiting..."
      exit 1
    elif test $yn = y -o $yn = Y; then
      rm $tmp_file
      break
    fi
    echo "delete it? choose y(yes) or n(no)"
  done
fi

echo "this is a test" >> $tmp_file
echo "Are you like awk" >> $tmp_file
echo "This's a test" >> $tmp_file
echo "There are orange,apple,mongo" >> $tmp_file

echo "********** awk '{print \$1}' filename **********" 
awk '{print $1}' $tmp_file # Note the single quotation marks !!
echo "************************************************"

echo "********* awk 'length(\$1)==3' filename ********" 
awk 'length($1)==3' $tmp_file # Note the single quotation marks !!
echo "************************************************"
echo

rm $tmp_file

