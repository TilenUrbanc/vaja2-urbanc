#!/bin/bash

set -e

echo "Zacenjam testiranje programa."

if [ -z "$CXX_STANDARD" ]; then
  CXX_STANDARD="17"
fi

echo "Uporabljam C++ standard: c++$CXX_STANDARD"

echo "Prevajam main.cpp."
g++ -std=c++$CXX_STANDARD main.cpp -o program

echo "Test 1: osnovno sortiranje."
echo "5 2 9 1 7 3" > input.txt

./program input.txt

rezultat=$(cat out.txt)
pricakovano="1 2 3 5 7 9"

if [ "$rezultat" != "$pricakovano" ]; then
  echo "Test 1 ni uspel."
  echo "Pricakovano: $pricakovano"
  echo "Dobljeno: $rezultat"
  exit 1
fi

echo "Test 1 je uspel."

echo "Test 2: sortiranje z 0 in 255."
echo "10 255 3 0 8" > input.txt

./program input.txt

rezultat=$(cat out.txt)
pricakovano="0 3 8 10 255"

if [ "$rezultat" != "$pricakovano" ]; then
  echo "Test 2 ni uspel."
  echo "Pricakovano: $pricakovano"
  echo "Dobljeno: $rezultat"
  exit 1
fi

echo "Test 2 je uspel."

echo "Test 3: ponovljene vrednosti."
echo "3 3 1 2 1" > input.txt

./program input.txt

rezultat=$(cat out.txt)
pricakovano="1 1 2 3 3"

if [ "$rezultat" != "$pricakovano" ]; then
  echo "Test 3 ni uspel."
  echo "Pricakovano: $pricakovano"
  echo "Dobljeno: $rezultat"
  exit 1
fi

echo "Test 3 je uspel."

echo "Vsi testi so uspeli."
