#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main()
{
    int n,sum=0;
    printf("enter the cataln number\n");
    scanf("%d",&n);
    printf("the catalan= %d",catalan(n));
    return 0;
}

int catalan(int n){
    int i=0,sum=0;
    //int x,y;
    if(n==0 ||n==1){
        return 1;
    }
    for(i=0;i<n;++i){
    sum=sum+catalan(i)*catalan(n-1-i);
    }
    return sum;
}
