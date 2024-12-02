/*题目编号 ：Exp04-Enhance03，freshman-1006
题目名称：英文翻译自然数
题目描述：按常规英文输出1000以内自然数的英文读法。
输入：每个测试输入包含 1 个测试用例，给出正整数 n（0<= n <1000）
输出：输出占一行：如果 0<= n <1000, 用规定的格式输出 n，所有英文单词小写，最后一个单词后无字符；否则输出ERR。
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
    h = n / 100;//百位
    m = n % 100;//十位与个位
    b = (m / 10)*10 ;//十位,后端置零如34->30
    a = m % 10;//个位
    
    if(h!=0){
        printf("%s hundred",NUMBER[h]);
        if(m!=0)
            printf(" and ");
        else
            return 0;//避免十分位或者个位为0导致one hundredzero或者one hundredzero-zero的意外情况，提前结束程序
    }
    if(m<=20){
        printf("%s",NUMBER[m]);
    }else
        printf("%s-%s",NUMBER[b],NUMBER[a]);
    
    return 0;
}