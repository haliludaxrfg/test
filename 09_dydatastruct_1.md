# ����������

��Ŀ����������дȱʧ������ɳ���ʵ�����¹��ܣ�

���ݴӼ������������0���������ɷ�������������һ��������֮�󽫴������б��������˳��������������ּ���һ�����Ŀո��������һ�����ֺ����κ��ַ������ǿ����������NULL��

���磬

����:
`5 4 2 1 3 0`

���:
`5 4 2 1 3`

����:
`0 5 4 2 1 3 0`

���:
`NULL`

***ע��***��

�ύ��ʱ����ճ��������Դ���룬��ճ����մ��Ĵ��뽫���д�
C���Բο�:

```c
#include <stdio.h>
#include <malloc.h>
struct cell { //��������ṹ�嶨��
 int x;
 struct cell* next;
};
struct cell* build(void) { //�½��������������õĵ������׽���ַ����
 struct cell* head,*tmp,*p;
 head = tmp = p = NULL;
 int n;
 /*��������λ�ò���������ʵ�ֺ���build�Ĺ���
       ......
       ......
       ......
   */
 return head;//���ص�����ͷ
}
void print(struct cell* head) {//��ӡ����������,head��ָ�������׽���ָ��
 /*��������λ�ò���������ʵ�ֺ���print�Ĺ���
       ......
       ......
       ......
   */
}
void release(struct cell* head) {//�ͷŵ�����ռ�,head��ָ�������׽���ָ��
 /*��������λ�ò���������ʵ�ֺ���release�Ĺ���
       ......
       ......
       ......
   */
}
int main(void) {
 struct cell* head;
 head = build();
 if(head!=NULL)
        print(head);
    else
        printf("NULL");
 release(head);
}
```
