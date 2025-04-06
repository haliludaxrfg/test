#include <bits/stdc++.h>
using namespace std;

int comp(char *a,char *b){
    int i=0,j=0;
    while (a[i]!='\0')
    {
        i++;
    }
    while (b[j]!='\0')
    {
        j++;
    }
    return abs(i>j);
    
}

int main(){
    char *a;
    char *b;
    gets(a);
    gets(b);
    cout << comp(a,b);
}