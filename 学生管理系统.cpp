#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <string.h>
#define LEN sizeof(struct student)
#define FORMAT "%-8d%-15s%-12.1lf%-12.1lf%-12.1lf%-12.1lf\n"
#define DATA stu[i].num,stu[i].name,stu[i].elec,stu[i].expe,stu[i].requ,stu[i].sum

struct student/*定义学生成绩结构体*/
{
    int num;/*学号*/
    char name[15];/*姓名*/
    double elec;/*选修课*/
    double expe;/*实验课*/
    double requ;/*必修课*/
    double sum;/*总分*/
};

// 全局变量定义结构体数组及记录条数
struct student stu[100];
int m = 0;

void in()/*录入学生信息*/
{ int i,m=0;/*m是记录的条数*/
  char ch[2];  
  FILE *fp;/*定义文件指针*/
  if((fp=fopen("data.txt","a+"))==NULL)/*以追加写入的方式打开指定文件*/
  { 
	  printf("can not open\n");
	  return;
  }
  while(!feof(fp))
  {
	  if(fread(&stu[m] ,LEN,1,fp)==1)
		  m++;/*统计当前记录条数*/
  }
  fclose(fp);
  if(m==0)
	  printf("No record!\n");
  else
  {
	  system("cls");
       show();/*调用show函数，显示原有信息*/
  }

  if((fp=fopen("data.txt","wb"))==NULL) //以写入的方式打开文件 
  {
	  printf("can not open\n");
	  return;
  }
  for(i=0;i<m;i++)
  {
   fwrite(&stu[i] ,LEN,1,fp);/*向指定的磁盘文件写入信息*/
  }

  printf("please input(y/n):");
  scanf("%s",ch);
  while(strcmp(ch,"Y")==0||strcmp(ch,"y")==0)/*判断是否要录入新信息*/
  	{
      printf("number:");
	  scanf("%d",&stu[m].num);/*输入学生学号*/
       for(i=0;i<m;i++)
	    if(stu[i].num==stu[m].num)
	    {
	    printf("the number is existing,press any to continue!");
	    getch();
	    fclose(fp);
	    return;
	    }
	
     printf("name:");
	 scanf("%s",stu[m].name);/*输入学生姓名*/

     printf("elective:");

     scanf("%lf",&stu[m].elec);/*输入选修课成绩*/
     printf("experiment:");
	 scanf("%lf",&stu[m].expe);/*输入实验课成绩*/
     printf("required course:");
	 scanf("%lf",&stu[m].requ);/*输入必修课成绩*/
     stu[m].sum=stu[m].elec+stu[m].expe+stu[m].requ;/*计算出总成绩*/
     if(fwrite(&stu[m],LEN,1,fp)!=1)/*将新录入的信息写入指定的磁盘文件*/
     {
		 printf("can not save!");
		 getch();
	 }
     else
	 {
		 printf("%s saved!\n",stu[m].name);
		 m++;
	 }
     printf("continue?(y/n):");/*询问是否继续*/
     scanf("%s",ch);
  }
  fclose(fp);
  printf("OK!\n");
}

void show()/*显示学生信息*/
 { FILE *fp;
   int i,m=0;
   fp=fopen("data.txt","rb");
   while(!feof(fp))
   {
   if(fread(&stu[m] ,LEN,1,fp)==1) 
   m++;
   }  
   fclose(fp);
   printf("number  name           elective    experiment  required    sum\t\n");
   for(i=0;i<m;i++)
       { 
	   printf(FORMAT,DATA);/*将信息按指定格式打印*/
       }
     }
// 查找学生信息
void search()
{
    int n, i;
    char s[15];
    FILE *fp;
    fp = fopen("data.txt", "rb");
    if (fp == NULL)
    {
        printf("Can not open file!\n");
        return;
    }
    while (!feof(fp))
    {
        if (fread(&stu[m], LEN, 1, fp) == 1)
            m++;
    }
    fclose(fp);
    printf("1. Search by number\n2. Search by name\nPlease choose: ");
    scanf("%d", &n);
    if (n == 1)
    {
        int num;
        printf("Please input the number: ");
        scanf("%d", &num);
        for (i = 0; i < m; i++)
        {
            if (stu[i].num == num)
            {
                printf(FORMAT, DATA);
                return;
            }
        }
        printf("Not found!\n");
    }
    else if (n == 2)
    {
        printf("Please input the name: ");
        scanf("%s", s);
        for (i = 0; i < m; i++)
        {
            if (strcmp(stu[i].name, s) == 0)
            {
                printf(FORMAT, DATA);
            }
        }
    }
    else
    {
        printf("Invalid choice!\n");
    }
}

// 删除学生成绩信息
void del()
{
    int n, i, j;
    FILE *fp;
    fp = fopen("data.txt", "rb");
    if (fp == NULL)
    {
        printf("Can not open file!\n");
        return;
    }
    while (!feof(fp))
    {
        if (fread(&stu[m], LEN, 1, fp) == 1)
            m++;
    }
    fclose(fp);
    printf("Please input the number of the student to delete: ");
    scanf("%d", &n);
    for (i = 0; i < m; i++)
    {
        if (stu[i].num == n)
        {
            for (j = i; j < m - 1; j++)
            {
                stu[j] = stu[j + 1];
            }
            m--;
            printf("Deleted successfully!\n");
            break;
        }
    }
    if (i == m)
    {
        printf("Not found!\n");
    }
    else
    {
        fp = fopen("data.txt", "wb");
        for (i = 0; i < m; i++)
        {
            fwrite(&stu[i], LEN, 1, fp);
        }
        fclose(fp);
    }
}

// 修改学生成绩信息
void modify()
{
    int n, i;
    FILE *fp;
    fp = fopen("data.txt", "rb");
    if (fp == NULL)
    {
        printf("Can not open file!\n");
        return;
    }
    while (!feof(fp))
    {
        if (fread(&stu[m], LEN, 1, fp) == 1)
            m++;
    }
    fclose(fp);
    printf("Please input the number of the student to modify: ");
    scanf("%d", &n);
    for (i = 0; i < m; i++)
    {
        if (stu[i].num == n)
        {
            printf("Number: %d\n", stu[i].num);
            printf("Name: %s\n", stu[i].name);
            printf("Elective: %lf\n", stu[i].elec);
            printf("Experiment: %lf\n", stu[i].expe);
            printf("Required: %lf\n", stu[i].requ);
            printf("Sum: %lf\n", stu[i].sum);
            printf("Please input new information:\n");
            printf("Name: ");
            scanf("%s", stu[i].name);
            printf("Elective: ");
            scanf("%lf", &stu[i].elec);
            printf("Experiment: ");
            scanf("%lf", &stu[i].expe);
            printf("Required: ");
            scanf("%lf", &stu[i].requ);
            stu[i].sum = stu[i].elec + stu[i].expe + stu[i].requ;
            printf("Modified successfully!\n");
            break;
        }
    }
    if (i == m)
    {
        printf("Not found!\n");
    }
    else
    {
        fp = fopen("data.txt", "wb");
        for (i = 0; i < m; i++)
        {
            fwrite(&stu[i], LEN, 1, fp);
        }
        fclose(fp);
    }
}
void menu()
 {
    printf("\n--- Student Information Management System ---\n");
    printf("1.录入学生成绩信息\n");
    printf("2.查找学生信息\n");
    printf("3.删除学生成绩信息\n");
    printf("4.修改学生成绩信息\n");
    printf("5.插入学生信息\n");
    printf("6.按总分排序\n");
    printf("7.计算总人数\n");
    printf("8.显示学生信息\n");
    printf("0.退出\n");
    printf("请选择操作：");
}

// 插入学生信息
void insert()
{
    int i;
    char ch[2];
    FILE *fp;
    fp = fopen("data.txt", "rb");
    if (fp == NULL)
    {
        printf("Can not open file!\n");
        return;
    }
    while (!feof(fp))
    {
        if (fread(&stu[m], LEN, 1, fp) == 1)
            m++;
    }
    fclose(fp);
    printf("Please input the information of the student to insert:\n");
    printf("Number: ");
    scanf("%d", &stu[m].num);
    for (i = 0; i < m; i++)
    {
        if (stu[i].num == stu[m].num)
        {
            printf("The number is existing,press any to continue!");
            getch();
            return;
        }
    }
    printf("Name: ");
    scanf("%s", stu[m].name);
    printf("Elective: ");
    scanf("%lf", &stu[m].elec);
    printf("Experiment: ");
    scanf("%lf", &stu[m].expe);
    printf("Required: ");
    scanf("%lf", &stu[m].requ);
    stu[m].sum = stu[m].elec + stu[m].expe + stu[m].requ;
    fp = fopen("data.txt", "ab");
    if (fp == NULL)
    {
        printf("Can not open file!\n");
        return;
    }
    fwrite(&stu[m], LEN, 1, fp);
    fclose(fp);
    m++;
    printf("Inserted successfully!\n");
}

// 按总分排序
void order()
{
    int i, j;
    struct student t;
    FILE *fp;
    fp = fopen("data.txt", "rb");
    if (fp == NULL)
    {
        printf("Can not open file!\n");
        return;
    }
    while (!feof(fp))
    {
        if (fread(&stu[m], LEN, 1, fp) == 1)
            m++;
    }
    fclose(fp);
    for (i = 0; i < m - 1; i++)
    {
        for (j = 0; j < m - i - 1; j++)
        {
            if (stu[j].sum < stu[j + 1].sum)
            {
                t = stu[j];
                stu[j] = stu[j + 1];
                stu[j + 1] = t;
            }
        }
    }
    printf("Number  Name   Elective    Experiment  Required    Sum\t\n");
    for (i = 0; i < m; i++)
    {
        printf(FORMAT, DATA);
    }
}

// 计算总人数
void total()
{
    FILE *fp;
    fp = fopen("data.txt", "rb");
    if (fp == NULL)
    {
        printf("Can not open file!\n");
        return;
    }
    while (!feof(fp))
    {
        if (fread(&stu[m], LEN, 1, fp) == 1)
            m++;
    }
    fclose(fp);
    printf("Total number of students: %d\n", m);
}
void main()/*主函数*/
{ int n;
  menu();
  scanf("%d",&n);/*输入选择功能的编号*/
  while(n)
  { switch(n)
     { case 1: in();break;
       case 2: search();break;
       case 3: del();break;
       case 4: modify();break;
       case 5: insert();break;
       case 6: order();break;
       case 7: total();break;
          case 8: show();break;
       default:break;
     }
    getch();
    menu();/*执行完功能再次显示菜单界面*/
    scanf("%d",&n);
  }
}
