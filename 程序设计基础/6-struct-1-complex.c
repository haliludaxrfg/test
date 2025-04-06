/*��Ŀ��� ��Exp07-Basic01
��Ŀ���ƣ���������
��Ŀ��������������д��A+Bi�ĳ�����ʽ������A��ʵ����B���鲿��i��������λ������i^2=-1��
��д���򣬷ֱ�������������ĺ͡������
���룺��һ�������θ�������������ʵ�����鲿�����ּ���һ�����Ŀո�ָ���
�����һ���а���A+Bi�ĸ�ʽ����������ĺ͡������ʵ�����鲿������2λС����
���B�Ǹ�������Ӧ��д��A-|B|i����ʽ�����B����������鲿���������4�����Ŀո�����*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    double real_part,imaginary_part;
}complex_type;

complex_type complex_sum (complex_type x,complex_type y){
    complex_type sum;
    sum.real_part = x.real_part + y.real_part;
    sum.imaginary_part=x.imaginary_part + y.imaginary_part;
  return sum;    
}

complex_type complex_minus (complex_type x,complex_type y){
    complex_type difference;
    difference.real_part = x.real_part - y.real_part;
    difference.imaginary_part=x.imaginary_part - y.imaginary_part;
  return difference;    
}

complex_type complex_mul(complex_type x, complex_type y){
    complex_type product;
    product.real_part = x.real_part * y.real_part
                        -x.imaginary_part * y.imaginary_part;
    product.imaginary_part = x.real_part * y.imaginary_part
                            +x.imaginary_part * y.real_part;
  return product;
}

void out(complex_type RES){
  printf("%.2lf",RES.real_part);
  if(RES.imaginary_part > 0)  
    printf("+%.2lfi",RES.imaginary_part);
  if(RES.imaginary_part < 0){
    printf("%.2lfi",RES.imaginary_part);}
}

int main(){
  complex_type x,y,SUM,DIFFERENCE,PRODUCT;
  scanf("%lf %lf %lf %lf",&x.real_part,&x.imaginary_part,&y.real_part,&y.imaginary_part);
  
  SUM = complex_sum(x,y);
  DIFFERENCE = complex_minus(x,y);
  PRODUCT = complex_mul(x,y); 
  
 out(SUM);
 printf("    ");
 out(DIFFERENCE);
 printf("    ");
 out(PRODUCT);
}