#! /bin/bash

algorithms=("B")
# declare -a algorithms=("B" "I" "U" "G" "A")

rm -f results/output.csv

echo "input,algorithm,expansions,time" >> results/output.csv

echo "Compiling..."
make
echo "Compiling done!"
echo

for algo in "${algorithms[@]}"; do
  for i in easy medium hard; do
    echo "Running $i input on $algo algorithm..."
    output=$(./main ${algo} $(<./data/$i.in))
    echo "$i,$algo,$output" >> results/output.csv
    echo "$i input on $algo done!"
  done
  echo
done