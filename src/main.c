//author: NiitaVen
#include <stdio.h>
#include <stdlib.h>

static int comparator(const void *a, const void *b);
double getThirdHighest(double* class1, double* class2);
void printClassHeight(double* class);

const int class_size = 23;

int main (int argc, char** argv)
{
  if (argc != class_size * 2 + 1)
  {
    printf("Wrong amount of arguments %d != %d\n", argc, class_size * 2 + 1);
    return -1;
    }
  
  double class1[class_size];
  double class2[class_size];

  for(int i = 0; i < class_size; ++i)
  {
    class1[i] = strtod(argv[i + 1], NULL);
    class2[i] = strtod(argv[i + class_size + 1], NULL);
    if(class1[i] <= 0 || class2[i] <= 0)
    {
      printf("Height is not positive or can't be parsed to double\n");
      return -2;
    }
  }
  
  int result = getThirdHighest(class1, class2);
  
  printf("\n1st class: ");
  printClassHeight(class1);

  printf("\n2nd class: ");
  printClassHeight(class2);
  
  printf("\nNumber of class where third highest is higher: %s\n" ,result > 0 ? "1" : !result ? "equals" : "2");
  return 0;
}

void printClassHeight(double* class)
{
  int size = sizeof(class)/sizeof(double);
  for(int i = 0; i < class_size; ++i)
    printf("%.1f ", class[i]);
  printf("\n");
}

double getThirdHighest(double* class1, double* class2)
{
  qsort(class1, class_size, sizeof(double), comparator);
  qsort(class2, class_size, sizeof(double), comparator);
  return comparator(&class2[2], &class1[2]);
}

static int comparator(const void *a, const void *b)
{
  if (*(double*)a > *(double*)b) 
    return -1;
  else if (*(double*)a < *(double*)b) 
    return 1;
  else 
    return 0; 
}