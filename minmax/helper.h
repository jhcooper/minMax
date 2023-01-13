#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct minMax {
  int min;
  int max;
};

struct minMax recursiveMinMax(int a[] , int start, int end);
struct minMax iterativeMinMax(int a[], int size);
