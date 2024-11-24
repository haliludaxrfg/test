#include <stdio.h>
#define SLEN 40
#define LIM 5

int main(){
    const char *mytalents[LIM]={
        "Adding numbers swiftly"
        "Multiplying accurately","Stashing data",
        "Following instructions to the letter",
        "Understanding the C lauguage"
        };
    char yourtalents[LIM][SLEN]={
        "Walking in a straight line",
        "Sleep","Watching television",
        "Mailing letters","Reading email"        
    };
    int i;
    puts("Let's compare talents.");
    printf("%-36s %-25s\n",mytalents[i],yourtalents[i]);
    printf("\nsizeof mytalents: %zd,sizof yourtalents: %zd\n",
            sizeof(mytalents),sizeof(yourtalents));
    return 0;
}