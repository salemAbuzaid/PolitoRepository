#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define str_length 101
#define word_length 21


int countword(char *a1,FILE *fp1){
    char array[word_length];
    int i=0;
    while (fscanf(fp1,"%s",array) !=EOF){

        if(strcmp(a1,array)==0){
            ++i;
        }
    }
    rewind(fp1);
    return i;
}

int main()
{
    char array1[str_length],array[word_length];
    int n;
    FILE *fp1;
    FILE *fp2;
    fp1 =fopen("fp1.txt","r");
    fp2 = fopen("fp2.txt","r");
    if (fp1==NULL){
        printf("error 1");
        exit(1);
    }

    if(fp2==NULL)
    {
        printf("error 2");
        exit(1);
    }
    fscanf(fp2,"%d",&n);

    while((fscanf(fp2,"%s",array))!=EOF){
      printf("%s\n",array);
      printf("%d\n",countword(array,fp1));
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}
