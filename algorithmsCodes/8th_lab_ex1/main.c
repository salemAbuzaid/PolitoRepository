#include <stdio.h>
#include <stdlib.h>
#include "new.h"


int main()
{
    int **mat;
    int n;
    char name[30];
    scanf("%d %s",&n,name);
    allocat(&mat,n);
    mat[0][0]=2;
    int val[9]={1,2,3,4,5,6,7,8,9};
    magic(n,mat,val);
    printf("Hello world!%d\n",mat[0][0]);
    return 0;
}
