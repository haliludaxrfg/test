/*10
��Ŀ��ţ�Exp04-Basic10��GJBook3-06-12
��Ŀ���ƣ��ַ�������
������������д���򣬽��������ַ������������
���룺һ�����Ȳ�����255���ַ������ַ����п��ܺ��пհ��ַ���
���������������ַ�����
����1��
���� A ��� A
����2��
���� 123 45 ��� 54 321*/
#include <stdio.h>
#include <string.h>

int main(){
    char s[255];
    int i=0;
    gets(s);           
    for(i=strlen(s)-1;i>=0;i--)
       printf("%c",s[i]);
}