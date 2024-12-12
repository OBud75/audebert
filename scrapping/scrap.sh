rm sitemap.xml
curl https://readi.fi/sitemap.xml | sed 's/<[^>]*>//g' > sitemap.xml

python find.py

