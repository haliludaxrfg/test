/*9
题目编号：Exp04-Basic09，GJBook3-06-02
题目名称：检验矩阵主对角线对称
题目描述：编写程序，判断任意给定nn的两维整型数组是否关于主对角线对称。
输入：第一行输入数组行数n（≤10），第二行随机输入nn个整数作为数组元素值。
输出：如果数组关于主对角线对称，则输出YES；否则输出NO。
样例1：
输入：
3
1 2 3
2 1 2
3 2 1
输出：
YES
样例2：
输入：
3
0 0 1
2 1 2
3 2 1
输出：
NO*/
#include <stdio.h>
int main(){
    int n,r,c;
    int Matrix[10][10];
    scanf("%d",&n);
    for(r=0;r<n;r++){
    for(c=0;c<n;c++){
            scanf("%d",&Matrix[r][c]);
        }
    }

    int ys=0;
    for(r=0;r<n;r++){
    for(c=0;c<n;c++){
            if(Matrix[r][c]!=Matrix[c][r]){
               ys=1;
               break;
            }if(ys==1)
            break;
        }if(ys==1)
        break;
    }

    if(ys==1)
     printf("NO");
    else
     printf("YES");
}