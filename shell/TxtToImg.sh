for file in $(ls test); do
  mv test/${file} test/${file%.txt}.img
done
