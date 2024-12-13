#!/bin/bash

# Configuration des variables
SOURCE_URL="https://example.com/sitemap.xml"
DATABASE_TYPE="sqlite" 
DATABASE_NAME="data_records"
TABLE_NAME="content"
CONTENT_PREFIX="https://example.com/resource"

if [ "$DATABASE_TYPE" = "sqlite" ]; then
    sqlite3 "$DATABASE_NAME.db" "CREATE TABLE IF NOT EXISTS $TABLE_NAME (id INTEGER PRIMARY KEY, link TEXT, heading TEXT, details TEXT);"
    echo "Table créée dans SQLite."
elif [ "$DATABASE_TYPE" = "postgres" ]; then
    psql -d "$DATABASE_NAME" -c "CREATE TABLE IF NOT EXISTS $TABLE_NAME (id SERIAL PRIMARY KEY, link TEXT, heading TEXT, details TEXT);"
    echo "Table créée dans PostgreSQL."
fi

curl -s "$SOURCE_URL" -o sitemap_data.xml

xmllint --xpath "//url/loc/text()" sitemap_data.xml | grep "^$CONTENT_PREFIX" > resource_links.txt

link_count=$(wc -l < resource_links.txt)
echo "Nombre de liens extraits: $link_count"

while IFS= read -r resource_url; do
    page_data=$(curl -s "$resource_url")
 
    heading=$(echo "$page_data" | sed -n 's:.*<title>\(.*\)</title>.*:\1:p')
    details=$(echo "$page_data" | sed -n 's/.*<meta name="description" content="\([^"]*\)".*/\1/p')
    
    resource_url_escaped=$(echo "$resource_url" | sed "s/'/''/g")
    heading_escaped=$(echo "$heading" | sed "s/'/''/g")
    details_escaped=$(echo "$details" | sed "s/'/''/g")
 
    if [ "$DATABASE_TYPE" = "sqlite" ]; then
        sqlite3 "$DATABASE_NAME.db" "INSERT INTO $TABLE_NAME (link, heading, details) VALUES ('$resource_url_escaped', '$heading_escaped', '$details_escaped');"
    elif [ "$DATABASE_TYPE" = "postgres" ]; then
        psql -d "$DATABASE_NAME" -c "INSERT INTO $TABLE_NAME (link, heading, details) VALUES ('$resource_url_escaped', '$heading_escaped', '$details_escaped');"
    fi

    echo "Enregistrement inséré pour le lien: $resource_url"
done < resource_links.txt

echo "Extraction et insertion terminées."

rm sitemap_data.xml resource_links.txt
