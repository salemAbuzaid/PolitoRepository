#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_size 10
int countspace(char *);
int main()
{
    char str[max_size];
    int n;
    printf("enter the string that wanted to count its space\n");
    gets(str);
    n=countspace(str);
    printf("the sum of spaces = %d",n);
    return 0;
}
int countspace(char *str){
    int cnt=0 ;
    if (*str=='\0'){
      return 0;
    }
    if (isspace(*str)){
        cnt=1;
            }
    cnt=cnt+ countspace(str+1);
    return cnt;
}
