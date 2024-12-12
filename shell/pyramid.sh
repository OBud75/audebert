#!/usr/bin/sh

# Définir le nombre de lignes pour le triangle
rows=6

for ((i=1; i<=rows; i++)); do
  for ((j=1; j<=i; j++)); do
    echo -n "*"  
  done
  echo "" 
done

