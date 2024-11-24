#include <stdio.h>
#include <complex.h>

void complexoutput(double complex cp){
    if(cimag(cp)==0)
        printf("%.2lf ",creal(cp));
    else if(cimag(cp)>0)
        printf("%.2lf+%.2lfi ",creal(cp),cimag(cp));
    else
        printf("%.2lf %.2lfi ",creal(cp),cimag(cp));
}
int main(){
    double x_real,x_imag,y_real,y_imag;
    scanf("%lf %lf %lf %lf",&x_real,&x_imag,&y_real,&y_imag);
    double complex x = x_real + x_imag * I;
    double complex y = y_real + y_imag * I;

    double complex SUM = x + y;
    double complex DIFFERENCE = x - y;
    double complex PRODUCT = x * y;

    complexoutput(SUM);
    complexoutput(DIFFERENCE);
    complexoutput(PRODUCT);
}

