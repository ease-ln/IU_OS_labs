#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
 int Integermax;
 float Floatmax;
 double Doublemax;

  Integermax = INT_MAX;
  Floatmax = FLT_MAX;
  Doublemax = DBL_MAX;

printf("INT MAX %d\n", Integermax);
printf("FLT_MAX %f\n", Floatmax);
printf("DBL MAX %f\n", Doublemax);

 return 0;
}
