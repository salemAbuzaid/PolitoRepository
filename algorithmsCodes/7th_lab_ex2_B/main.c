#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int main()
{
    int decimal,n=0,i;
    printf("enter the decimal number\n");
    scanf("%d",&decimal);
    int *b=NULL;
    printf ("the binary representation\n");
    d2b(decimal,&b,&n);
    for(i=0;i<n;++i){
        printf("%d \n",b[i]);
    }
    printf("\nn= %d\n",n);
    return 0;
}

void d2b(int d,int **b,int* n){
    *n = *n +1;
    int i=*n;
    if (d==1){
        *b=realloc(*b,(*n)*sizeof(int));
        *b[--i]=1;
         //printf("%d",b[i]);
        return ;
    }
    *b=realloc(*b,(*n)*sizeof(int));
    d2b(d/2,b, n);
    *b[--i]=d%2;
    //printf("%d",b[i]);
    return;
}
