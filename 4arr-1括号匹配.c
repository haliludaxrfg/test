/*1. (括号匹配)
题目编号：Exp04-Basic01,GJBook3例-06-13
题目名称：括号匹配
题目描述：编写程序，从终端读入以‘@’为结束符的字符序列，检查该字符序列中的 ( 与 )、
 [ 与 ] 、{ 与 } 是否匹配（个数相等且位置不相交）。
输入：包含一串以‘@’为结束符的字符串，其间可能包含空白或其它非括号字符。
输出：如果字符串中三类括号匹配，则输出YES；否则输出NO。
样例1:
输入：
{a,a}b{c[cc]c}  {a(bb[cc]dd)a}@
输出：
YES
样例2:
输入：
{a,a}b{c[cc]c] {a(bb[cc]dd)a}@
输出：
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