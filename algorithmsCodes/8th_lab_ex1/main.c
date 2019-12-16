#include "new.h"


int main()
{
    int **mat = NULL,*used = NULL,*val = NULL;
    int n,t;
    //char name[30];
    printf("enter the size of the magic matrix\n");
    scanf("%d",&n);
    allocat(&mat,&used,&val,n);
    fillval(val,used,n);
    /*
    for(t=0;t<n*n;++t){
        printf("used=%2d val%2d\n",used[t],val[t]);
    }*/
    if(magic(mat,val,used,n,0)){
        printf("the magic is found\n");
        printmat(mat,n);
    }else{
    printf("magic is not found\n");
    }
    return 0;
}
