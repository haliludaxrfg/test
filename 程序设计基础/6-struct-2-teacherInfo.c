/*����һ����ʾ��ʦ�Ľṹ�壨����3���ֶΣ��������Ա����䣩����д������
����n����ʦ����Ϣ������һ���ṹ�������У�����ͼ��ʾ������������n/2����ʦ����Ϣ��*/
#include <stdio.h>

typedef struct teacherInfo
{
    char name[20];
    int sex;
    int age;
}teacherInfo;

int main(){
    int n;scanf("%d",&n);
    teacherInfo info[14];
    for(int i = 0;i < n; i++){
        scanf("%s",&info[i].name);
        scanf("%d",&info[i].sex);
        scanf("%d",&info[i].age);
    }
    n/=2;
    if(info[n].sex == 0)
        printf("%s Female %d",info[n].name,info[n].age);
    else
        printf("%s Male %d",info[n].name,info[n].age);
}
