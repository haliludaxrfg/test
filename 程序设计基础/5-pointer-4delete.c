/*4. (程序题)
题目编号 ：Exp05-Basic04，GJBook3-07-11
题目名称：字符串部分删除
题目描述：
编写程序实现：使用自编函数char * str_delete(char *s, int v, int w)
从字符串s的第v个字符开始删除w个字符，并将处理后的字符串首地址以函数返回值
带回调用点。
输入：
第一行输入两个整数分别对应 v和w（0≤v, w<MIN(256,strlen(s))）,
测试数据已保证v和w符合要求；
第二行输入一个长度不超过256的字符串，字符串可能含有空格。
输出：
处理后的字符串。
样例：
输入：
2 6
ABCDEFGH 12345
输出：
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