#!/bin/bash

if [ "$1" == -i ]; then
  optional_argument=$1
  shift
fi

if [ $# -ne 2 ]; then
  echo "Usage: $0 [-i] <keyword> <path>"
  echo "Options:"
  echo "  -i:  ignore case distinctions"
  exit 1
fi

keyword=$1
path=$2

for file in $path/*; do
  if [ -f $file ]; then
    grep $optional_argument $keyword $file >> /dev/null && echo $file
  fi
done

