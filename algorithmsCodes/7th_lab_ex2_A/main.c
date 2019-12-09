#include <stdio.h>
#include <stdlib.h>
#include"header.h"
int main()
{
    int x=0,y=0,result;
    printf("insirt the two numbers\n");
    scanf("%d %d",&x,&y);
    result= mult(x,y);
    printf("mult= %d",result);
    return 0;
}

int mult(int x,int y)
{
    //int result;
    if(y==1){
        return x;
    }
    //result =x*y;
    return (y*mult(x,(y-1)));
}
