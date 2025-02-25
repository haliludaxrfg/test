#include <stdio.h>

typedef struct{
    int ATK;
    int DEF;
}sword;

int main(){
    int n;
    scanf("%d",&n);
    sword swords[1007];
    for(int i=0;i<n;i++){
        scanf("%d%d",&swords[i].ATK,&swords[i].DEF);
    }

    int MaxSum = 0;
    int left = 0;
    int right =0;
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            int MaxATK = swords[i].ATK>swords[k].ATK?swords[i].ATK:swords[k].ATK;
            int MinDEF = swords[i].DEF<swords[k].DEF?swords[i].DEF:swords[k].DEF;
            if(MaxATK+MinDEF>MaxSum){
                MaxSum = MaxATK+MinDEF;
                left = i;
                right = k;
            }
        }
    }

    printf("%d %d",left+1,right+1);
}