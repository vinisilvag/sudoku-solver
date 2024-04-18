#! /bin/bash

declare -a algorithms=("B")
# declare -a algorithms=("B" "I" "U" "A" "G")

rm -f results/output.csv

echo "input,algorithm,expansions,time" >> results/output.csv

make

for i in 01 02 03; do
  for algo in "${algorithms[@]}"; do
    output=$(./main ${algo} $(<./data/$i.in))
    echo "$i,$algo,$output" >> results/output.csv
  done
done