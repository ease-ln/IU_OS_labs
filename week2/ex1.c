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
    printf("INT MAX %lu\n", sizeof(Integermax));
    printf("FLT_MAX %lu\n", sizeof(Floatmax));
    printf("FLT_MAX %lu\n", sizeof(Doublemax));

    return 0;
}
