/*题目编号 ：Exp07-Basic01
题目名称：复数运算
题目描述：复数可以写成A+Bi的常规形式，其中A是实部，B是虚部，i是虚数单位，满足i^2=-1。
编写程序，分别计算两个复数的和、差、积。
输入：在一行中依次给出两个复数的实部和虚部，数字间以一个西文空格分隔。
输出：一行中按照A+Bi的格式输出两虚数的和、差、积，实部和虚部均保留2位小数；
如果B是负数，则应该写成A-|B|i的形式；如果B是零则不输出虚部；结果间以4个西文空格间隔。*/
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