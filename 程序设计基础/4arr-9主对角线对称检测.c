/*9
��Ŀ��ţ�Exp04-Basic09��GJBook3-06-02
��Ŀ���ƣ�����������Խ��߶Գ�
��Ŀ��������д�����ж��������nn����ά���������Ƿ�������Խ��߶Գơ�
���룺��һ��������������n����10�����ڶ����������nn��������Ϊ����Ԫ��ֵ��
������������������Խ��߶Գƣ������YES���������NO��
����1��
���룺
3
1 2 3
2 1 2
3 2 1
�����
YES
����2��
���룺
3
0 0 1
2 1 2
3 2 1
�����
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