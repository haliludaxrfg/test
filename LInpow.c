#include <stdio.h>
int b;
void judge(int x1, int x2, int n);
int main()
{
    int n, i = 0, x, a[100], flag = 0, x1, x2, m;
    scanf("%d", &n);
    do
    {
        i = 0;
        b = 0;
        scanf("%d", &x);
        a[i] = x;
        i++;
        if (x == -1)
        {
            break;
        }
        if (flag)
        {
            printf("\n");
        }
        while (x != 0)
        {

            scanf("%d", &x);
            a[i] = x;
            i++;
        }
        for (int j = 0; j <= i; j++)
        {
            for (m = j + 1; m <= i; m++)
            {
                x1 = a[j];
                x2 = a[m];
                judge(x1, x2, n);
                flag = 1;
            }
        }
        printf("%d", b);
    } while (x != -1);
    return 0;
}
void judge(int x1, int x2, int n)
{
    if (x1 == x2 * n || x2 == x1 * n)
    {
        b++;
    }
}