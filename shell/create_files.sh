#!/usr/bin/env bash

# Fonction pour créer le répertoire et les fichiers
create_files() {
  local dir="test"
  
  if [[ ! -d $dir ]]; then
    mkdir "$dir" || { echo "Erreur : Impossible de créer le répertoire $dir"; exit 1; }
  fi
  
  # Crée 15 fichiers avec des noms incrémentés
  for i in {1..15}; do
    touch "$dir/pates${i}.txt" || { echo "Erreur : Impossible de créer $dir/pates${i}.txt"; exit 1; }
  done
  
  echo "Création réussie : Répertoire '$dir' et fichiers."
}

clean_up() {
  local dir="test"

  if [[ -d $dir ]]; then
    rm -rf "$dir" || { echo "Erreur : Impossible de supprimer le répertoire $dir"; exit 1; }
    echo "Nettoyage réussi : Répertoire '$dir' supprimé."
  else
    echo "Le répertoire '$dir' n'existe pas. Rien à nettoyer."
  fi
}

if [[ $1 == "clean" ]]; then
  clean_up
else
  create_files
fi
