/*构造一个表示教师的结构体（包含3个字段：姓名、性别、年龄），编写函数，
读入n个教师的信息，存入一个结构体数组中（如下图所示）。最后输出第n/2个教师的信息。*/
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
