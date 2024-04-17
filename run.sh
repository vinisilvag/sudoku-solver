#! /bin/bash

declare -a algorithms=("B" "I" "U" "A" "G")

make

for i in 01 02 03; do
  for algo in "${algorithms[@]}"; do
    ./main ${algo} $(<./experiments/input/$i.in) > ./experiments/output/${algo}-$i.out
  done
done