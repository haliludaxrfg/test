/*��Ŀ��� ��Exp04-Enhance03��freshman-1006
��Ŀ���ƣ�Ӣ�ķ�����Ȼ��
��Ŀ������������Ӣ�����1000������Ȼ����Ӣ�Ķ�����
���룺ÿ������������� 1 ���������������������� n��0<= n <1000��
��������ռһ�У���� 0<= n <1000, �ù涨�ĸ�ʽ��� n������Ӣ�ĵ���Сд�����һ�����ʺ����ַ����������ERR��
*/
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <stdio.h>

char NUMBER[100][12] = {"zero","one","two","three","four","five","six","seven","eight","nine","ten"
                        ,"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen","twenty",
                        "Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder",
                        "thirty","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder",
                        "forty","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder",
                        "fifty","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder",
                        "sixty","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder",
                        "seventy","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder",
                        "eighty","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder","Placeholder",
                        "ninety"};

int main(){
    int n;scanf_s("%d",&n);
    
    int h,m,b,a;
    h = n / 100;//��λ
    m = n % 100;//ʮλ���λ
    b = (m / 10)*10 ;//ʮλ,���������34->30
    a = m % 10;//��λ
    
    if(h!=0){
        printf("%s hundred",NUMBER[h]);
        if(m!=0)
            printf(" and ");
        else
            return 0;//����ʮ��λ���߸�λΪ0����one hundredzero����one hundredzero-zero�������������ǰ��������
    }
    if(m<=20){
        printf("%s",NUMBER[m]);
    }else
        printf("%s-%s",NUMBER[b],NUMBER[a]);
    
    return 0;
}