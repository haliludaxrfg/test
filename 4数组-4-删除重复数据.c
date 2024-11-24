/*4
题目编号：Exp04-Basic04，GJBook3-06-19
题目名称：删除重复元素
题目描述：编写函数，不使用其他辅助数组，把整型数组中重复元素删得只剩一个；所有未被删除元素都保留最先顺序移动到数组前面。
输入：第一行输入数组长度n（≤100），第二行依次从键盘随机输入n个整数作为数组元素值。
输出：已删除重复元素的数组，各元素间以一个西文空格间隔，最后一个元素后无字符。
样例1：
输入：
10
1 1 2 3 3 3 2 1 2 4
输出：
1 2 3 4
样例2：
输入：
10
1 0 2 2 2 2 2 2 2 2
输出：
1 0 2*/
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int i=0;
    scanf("%d",&n);
    int arr[100]={0};
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int pd=0;
    printf("%d ",arr[0]);
    for(i=1;i<n;i++){
        pd=0;
        for(int k=0;k<i;k++){
            if(arr[i]==arr[k]){
               pd=1;break;
            }
        }    
        if(!pd){
            printf("%d ",arr[i]);
        } 
    }    
    return 0;
}