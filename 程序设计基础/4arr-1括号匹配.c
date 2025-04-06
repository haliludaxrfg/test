/*1. (����ƥ��)
��Ŀ��ţ�Exp04-Basic01,GJBook3��-06-13
��Ŀ���ƣ�����ƥ��
��Ŀ��������д���򣬴��ն˶����ԡ�@��Ϊ���������ַ����У������ַ������е� ( �� )��
 [ �� ] ��{ �� } �Ƿ�ƥ�䣨���������λ�ò��ཻ����
���룺����һ���ԡ�@��Ϊ���������ַ����������ܰ����հ׻������������ַ���
���������ַ�������������ƥ�䣬�����YES���������NO��
����1:
���룺
{a,a}b{c[cc]c}  {a(bb[cc]dd)a}@
�����
YES
����2:
���룺
{a,a}b{c[cc]c] {a(bb[cc]dd)a}@
�����
NO*/
#include <stdio.h>
#define size 1000
int main(void)
{
    char stack[size], ch;
    int top = 0, flag = 1;
    stack[top] = '@';
    top++;
    ch = getchar();
    while (ch != '@')
    {
        switch (ch)
        {
        case '(':;
        case '[':;
        case '{':
            stack[top] = ch;
            top++;
        case ')':
            if (stack[top - 1] == '(')

                top--;

            else

                flag = 0;
            ;
            break;
        case ']':
            if (stack[top - 1] == '[')

                top--;

            else

                flag = 0;
            ;
            break;
        case '}':
            if (stack[top - 1] == '{')

                top--;

            else

                flag = 0;
            ;
            break;
        }
        ch = getchar();
    }
    if (flag)

        printf("YES");

    else

        printf("NO");

    return 0;
}