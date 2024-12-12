#!/usr/bin/sh

#!/usr/bin/env bash

display_table() {
  local number=$1
  local limit=10 
  echo "Table de multiplication pour : $number"
  echo "-------------------------------"
  for ((i=1; i<=limit; i++)); do
    echo "$i * $number = $((i * number))"
  done
}

if [[ "$1" =~ ^[0-9]+$ ]]; then
  display_table $1
else
  echo "Erreur : \"$1\" n'est pas un entier positif."
  echo "Usage : $0 <nombre entier positif>"
fi
