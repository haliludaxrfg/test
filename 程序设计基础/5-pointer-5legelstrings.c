/*5. (������)
��Ŀ��ţ�Exp05-Enhanc02��freshman-1031
��Ŀ���ƣ��Ϸ���ʶ��
��Ŀ������
��֪C�����кϷ���ʶ�Ķ����ǣ���_����ĸ��ʼ������_�����֡���ĸ���ɵ������ַ�������д�����жϸ������ַ����Ƿ��ǺϷ�C���Ա�ʶ����
���룺�����һ�и��������� N����10^2����������ַ������������ N �У�ÿ�и���1�����ⳤ�ȵ��ַ��������ܺ��пհ��ַ������Ȳ�����256����
�����
�����һ����Valid:X ��ʽ�����Ϸ���ʶ������ X���ڶ�����Invalid:Y ��ʽ�����Ƿ���ʶ������ Y���޶����ַ���ð��Ϊ����ð�š�
������
���룺
2
1242345567788990
abcdedffesfsgfef
�����
Valid:1
Invalid:1*/
#include <stdio.h>
#include <string.h>
int Valid=0,Invalid=0;
void check(char *s,int l){
    int i=0,r=1;
    for(i=0;i<l;i++){
        r=0;
        if(i==0&&(s[i]==95||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122))&&s[i]!=32)//��һ��»��ߴ�Сд
          r=1;
        if(i!=0&&(s[i]==95||(s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57))&&s[i]!=32) //�������»��ߴ�Сд����
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