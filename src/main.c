
#include <stdio.h>
#include <stdlib.h>

const int class_size = 23;

static int comparator(const void *a, const void * b)
{
  if (*(double*)a > *(double*)b) 
    return 1;
  else if (*(double*)a < *(double*)b) 
    return -1;
  else 
    return 0; 
}

double getThirdHighest(double* class1, double* class2)
{
  qsort(class1, class_size, sizeof(double), comparator);
  qsort(class1, class_size, sizeof(double), comparator);
  return comparator(&class1[2], &class2[2]);
}

int main (int argc, char** argv)
{
  if (argc != class_size * 2 + 1)
    printf("Wrong amount of arguments %d != %d", argc, class_size * 2 + 1);
  
  double class1[class_size];
  double class2[class_size];

  for(int i = 0; i < class_size; ++i)
  {
    class1[i] = strtod(argv[i + 1], NULL);
  }
  for(int i = class_size; i < class_size * 2; ++i)
  {
    class2[i] = strtod(argv[i + 1], NULL);
  }
  
  return 0;
}
