#include <stdio.h>
#define pi 3.1415926
int main()
{
    double C,F;
    printf("Please input angular value");
    scanf("%lf",&C);
    F=C/180.0*pi;
    printf("%lf",F);
    return 0;
}