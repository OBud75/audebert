#include <stdio.h>

int main(int argc, char *argv[])
{
  int a = 12;
  
  int* ptr_a = &a;

  printf("%d\n", *ptr_a);

  return 0;
}
