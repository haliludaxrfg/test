#include <stdio.h>
#include <math.h>
struct tri
{
    int x,y;
};
void getlen(struct tri z[],float *a,float *b,float *c)
{//
    *a=sqrt((z[0].x-z[1].x) *(z[0].x-z[1].x) +(z[0].y-z[1].y) *(z[0].y-z[1].y));
    *b=sqrt((z[1].x-z[2].x) *(z[1].x-z[2].x) +(z[1].y-z[2].y) *(z[1].y-z[2].y));
    *c=sqrt((z[0].x-z[2].x) *(z[0].x-z[2].x) +(z[0].y-z[2].y) *(z[0].y-z[2].y));
}//
float sumlen(struct tri z[])
{
    float a,b,c;
    getlen(/**/z,&a,&b,&c);//
    if(a+b==c||a+c==b||b+c==a)//共线检测
        return 0;
    return a+b+c;   
}//
int main(void)
{
    int i;
    float len;
    struct tri z[3];
    for(i=0;i<3;i++)
    {
        scanf("%d %d",&z[i].x,&z[i].y);
    }
    //
    len = sumlen(z);
    
    //
    if(len>0)
        printf("%.2f",len);
    else
        printf("%d %d %d %d %d %d",z[0].x,z[0].y,z[1].x,z[1].y,z[2].x,z[2].y);
    return 0;
}