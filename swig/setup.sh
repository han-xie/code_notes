#!/usr/bin/env bash

# Reference:
# https://www.it610.com/article/1281966820936400896.htm

CXX=g++


${CXX} -c -fPIC mod_cal.cpp
if ! which swig > /dev/null; then
  echo "$0: swig is not installed, you can install with"
  echo "    sudo apt install swig (in ubuntu)"
  exit 1;
fi

# Without -c++ option, swig will generate a C-version wrapper
swig -python -c++ mod_cal.i

${CXX} -fPIC -shared mod_cal_wrap.cxx mod_cal.o -o _mod_cal.so -I/usr/include/python2.7

if /usr/bin/python2.7 single_test.py; then
  echo "test passed"
else
  echo "test NOT passed"
fi

