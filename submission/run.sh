#!/bin/bash

algorithms=("B" "I" "U" "G" "A")
numbers=("1" "2" "3" "4" "5" "6" "7" "8" "9")

rm -f results/output.csv

echo "difficulty,input,clues,algorithm,expansions,time" >> results/output.csv

echo "Compiling..."
make clean
make
echo "Compiling done!"
echo

for algo in "${algorithms[@]}"; do
  for i in easy medium hard; do
    for instance_path in data/$i/*.in; do
      instance=${instance_path##*/}
      content=$(<$instance_path)
      count=0
      for ((j = 0; j < ${#content}; j++)); do
        char="${content:j:1}"
        if [[ ${numbers[@]} =~ $char ]]
        then
          count=$((count + 1))
        fi
      done
      echo "Running $i - $instance input on $algo algorithm..."
      output=$(./main ${algo} $(<$instance_path))
      echo "$i,${instance::-3},$count,$algo,$output" >> results/output.csv
      echo "$i - $instance input on $algo done!"
    done
    echo
  done
  echo "--------------------------"
done