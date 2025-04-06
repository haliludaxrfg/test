#include <bits/stdc++.h>
int n;
int a[100] = {0};
int check(int sit);
void dfs(int x, int sit)
{
    int i, k;
    for (i = x - 1; i > 0; i--)
    {
        a[sit] = i;
        a[sit + 1] = x - i;
        if (check(sit + 1))
        {
            int tem = 0;
            printf("%d=", n);
            for (int i = 0; i <= sit + 1; i++)
            {
                if (tem)
                    printf("+");
                tem = 1;
                printf("%d", a[i]);
            }
            printf("\n");
        }
        if (a[sit + 1] > 1)
            dfs(x - i, sit + 1);
    }
}

int check(int sit)
{
    for (int i = 0; i < sit; i++)
        if (a[i] < a[i + 1])
            return 0;
    return 1;
}

int main(void)
{
    scanf("%d", &n);
    dfs(n, 0);
    return 0;
}