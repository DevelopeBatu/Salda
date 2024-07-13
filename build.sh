#!/bin/bash


if [ -z "$1" ]; then
  echo "No argument provided, building in build directory..."
  mkdir -p build
  cd build
  cmake..
  make
  ./Salda ../main.sl
else
  if [ "$1" = "test" ]; then
    echo "Running tests..."
    gcc -o test/test test/test.c
    ./test/test
  else
    echo "Unknown argument: $1"
    exit 1
  fi
fi