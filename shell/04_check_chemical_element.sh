#!/bin/bash

# Copyright 2024 Han Xie

# This script can be used to check whether the input text is
# the symbol of a chemical element or not

if [ $# -ne 1 ]; then
  echo "Usage: $0 <element_symbol>"
  exit 1
fi

element_symbol=$1

# user-defined function
# references: https://bash.cyberciti.biz/guide/Pass_arguments_into_a_function
is_chemical_element() {
  local symbol=$1
  var=$(awk -v sym=$symbol 'BEGIN{
  strElements="Ac Ag Al Am Ar As At Au B Ba Be Bh Bi Bk Br C Ca Cd Ce Cf Cl Cm Cn Co Cr Cs Cu Db Ds Dy Er Es Eu F Fe Fm Fr Ga Gd Ge H He Hf Hg Ho Hs I In Ir K Kr La Li Lr Lu Md Mg Mn Mo Mt N Na Nb Nd Ne Ni No Np O Os P Pa Pb Pd Pm Po Pr Pt Pu Ra Rb Re Rf Rg Rh Rn Ru S Sb Sc Se Sg Si Sm Sn Sr Ta Tb Tc Te Th Ti Tl Tm U Uuh Uuo Uup Uuq Uus Uut V W Xe Y Yb Zn Zr"
  n = split(strElements, arrElements)
  for (i in arrElements) {if (arrElements[i] == sym) {print 1}}
  }')
  if [ "$var" != "1" ]; then
    var=0
  fi
#  echo $var
  return $var
}

is_chemical_element $element_symbol
check_result=$?
if [ "$check_result" == "1" ]; then
  echo $element_symbol is a chemical element;
else
  echo $element_symbol is NOT a chemical element;
fi

exit 0