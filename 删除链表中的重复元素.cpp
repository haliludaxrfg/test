#include <bits/stdc++.h>
struct cell
{
    int x;
    char name[1000];//字符数字储存姓名
    int age;
    struct cell* next;
};
 
struct cell *build(int num)//输入链表
{
	struct cell *tmp;
    struct cell *headA = (struct cell*)malloc(sizeof(struct cell));
	scanf("%d %s %d",&headA->x,headA->name,&headA->age);//注意字符串的输入方法
    struct cell *end = headA;
	for(int i=0; i<num-1; i++)//输入num个元素
	{
		tmp = (struct cell*)malloc(sizeof(struct cell));
	    scanf("%d %s %d",&tmp->x,tmp->name,&tmp->age);
		end->next = tmp;
		end = tmp; 
	}
	end->next = NULL;
	return headA;
}
 
void print(struct cell* head)//输出链表
{
    struct cell* p;
    p=head;
    while(p!=NULL)
    {
        printf("%d %s %d\n",p->x,p->name,p->age);
        p=p->next;
    }
}
void release(struct cell* head)//释放链表所占用的空间
{
    struct cell *p,*tmp;
    p=tmp=head->next;
    while(p!=NULL)
    {
        tmp=p;
        p=p->next;
        free(tmp);
    }
    p=head=tmp=NULL;
}
 
struct cell* delCell(struct cell *head,int n)//铲除含n的元素
{//
    struct cell* dummy=(struct cell*)malloc(sizeof(struct cell));
    struct cell* cur = dummy; 
    dummy->next = head;
    while (cur->next!=NULL)
    {
        if(cur->next->age==n){
            struct cell* tmp = cur ->next;
            cur->next = cur ->next->next;
            free (tmp);
        }else{
            cur = cur->next;
        }
    } 
    head = dummy->next;
    free(dummy);
    return head;
}//
 
int main(void)
{
    struct cell*head;
    int num,n;
    scanf("%d",&num);
    head=build(num);
    scanf("%d",&n);
    head=delCell(head,n);
    print(head);
    release(head);
    return 0;
}