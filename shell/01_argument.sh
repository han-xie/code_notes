#!/bin/bash

# References:
# [shift](https://www.cnblogs.com/image-eye/archive/2011/08/20/2147153.html)
# [passing arguments](https://www.runoob.com/linux/linux-shell-passing-arguments.html)

optional_argument=false

if [ "$1" == --opt ]; then
  optional_argument=true
  shift
fi

if [ $# -ne 3 ]; then
  echo "Usage: $0 [--opt] <arg-1> <arg-2> <arg-3>"
  exit 1
fi

if [ $optional_argument == true ]; then
  echo "--opt argument specified"
else
  echo "--opt argument NOT specified"
fi

echo "First argument is $1"
echo "Second argument is $2"
echo "Third argument is $3"

