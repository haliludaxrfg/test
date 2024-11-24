/*5. (程序题)
题目编号：Exp05-Enhanc02，freshman-1031
题目名称：合法标识符
题目描述：
已知C语言中合法标识的定义是，以_或字母开始，并由_、数字、字母构成的连续字符串。编写程序判断给定的字符串是否是合法C语言标识符。
输入：输入第一行给出正整数 N（≤10^2）是输入的字符串个数。随后 N 行，每行给出1个任意长度的字符串（可能含有空白字符，长度不超过256）。
输出：
输出第一行以Valid:X 格式给出合法标识符个数 X，第二行以Invalid:Y 格式给出非法标识符个数 Y，无多余字符，冒号为西文冒号。
样例：
输入：
2
1242345567788990
abcdedffesfsgfef
输出：
Valid:1
Invalid:1*/
#include <stdio.h>
#include <string.h>
int Valid=0,Invalid=0;
void check(char *s,int l){
    int i=0,r=1;
    for(i=0;i<l;i++){
        r=0;
        if(i==0&&(s[i]==95||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))&&s[i]!=32)//第一项，下划线大小写
          r=1;
        if(i!=0&&(s[i]==95||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57))&&s[i]!=32) //其它项下划线大小写数字
          r=1;
        if(r!=0)
        break;
    }
    if(r==0)
    Invalid++;
    if(r==1)
    Valid++;    

}
int main(){
    int N=0;
    int l=0;
    scanf("%d",&N);
    getchar();
    char s[260];

    for(int i=0;i<N;i++){
        gets(s);
        l=strlen(s);
        check(s,l);
        memset(s,'\0',260);
    }

    printf("Valid:%d\nInvalid:%d",Valid,Invalid);
}