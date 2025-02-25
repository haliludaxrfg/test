// 公式法
/*一元三次方程:aX^3+b^X2+cX+d=0
 重根判别公式：
       A=b的二次方-3ac
       B=bc-9ad
       C=c的二次方-3bd
 当A=B=0时，X1=X2=X3= -b/3a= -c/b = -3d/c*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a, b, c, d;
    double as, bs, t, si;
    double x[3];
    cin >> a >> b >> c >> d;
    as = b * b - 3 * a * c;
    bs = b * c - 9 * a * d;
    t = (2 * as * b - 3 * a * bs) / (2 * sqrt(as * as * as));
    si = acos(t);
    x[0] = (-b - 2 * sqrt(as) * cos(si / 3)) / (3 * a);
    x[1] = (-b + sqrt(as) * (cos(si / 3) + sqrt(3) * sin(si / 3))) / (3 * a);
    x[2] = (-b + sqrt(as) * (cos(si / 3) - sqrt(3) * sin(si / 3))) / (3 * a);
    sort(x, x + 3);
    printf("%.2lf %.2lf %.2lf\n", x[0], x[1], x[2]);
    return 0;
}

