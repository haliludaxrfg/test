/*4. (������)
��Ŀ��� ��Exp05-Basic04��GJBook3-07-11
��Ŀ���ƣ��ַ�������ɾ��
��Ŀ������
��д����ʵ�֣�ʹ���Աຯ��char * str_delete(char *s, int v, int w)
���ַ���s�ĵ�v���ַ���ʼɾ��w���ַ��������������ַ����׵�ַ�Ժ�������ֵ
���ص��õ㡣
���룺
��һ���������������ֱ��Ӧ v��w��0��v, w<MIN(256,strlen(s))��,
���������ѱ�֤v��w����Ҫ��
�ڶ�������һ�����Ȳ�����256���ַ������ַ������ܺ��пո�
�����
�������ַ�����
������
���룺
2 6
ABCDEFGH 12345
�����
AH 12345*/
#include <stdio.h>
#include <string.h>

void cover(char* str,int v,int w,int len){
  int i, j;
  for (i = v-1, j = v + w-1; j < len; i++, j++) {
        str[i] = str[j];
  }
  str[len-w] = '\0';
} 

int main(){
    int v=0,w=0;
    scanf("%d %d\n",&v,&w);
    char str[256];
    gets(str);
    
    int len=strlen(str);

    cover(str,v,w,len);

    printf("%s",str);    

    return 0;
}