#include <stdio.h>

typedef struct Birthday{
    int year;
    int month;
    int day;
}Birthday;

typedef struct Student{
    int id;
    char *name;
    int age;
    double score;
    Birthday birthday;
}Student;

void printStudentInfo(Student *pStu,int len){
    for(int i = 0;i<len;++i ){
        printf("id:%d name:%s age:%d score:%.2f Bit:%d-%d-%d\n",
                (pStu+i)->id,(pStu+i)->name,(pStu+i)->age,(pStu+i)->score,
                (pStu+i)->birthday.year,(pStu+i)->birthday.month,(pStu+i)->birthday.day);
    }
}

int main(){
    Student stu[] = {
        {114514,"0d00",18,100,{2015,7,21}},
        {1919810,"otto",24,99,{2000,8,8}}
    };

    printStudentInfo(stu,sizeof(stu)/sizeof(stu[0]));
    

    //printf("生日结构体占地空间：%d\n",sizeof(Birthday));
    //printf("学生结构体占地空间：%d\n",sizeof(Student));
    return 0;
}
    
