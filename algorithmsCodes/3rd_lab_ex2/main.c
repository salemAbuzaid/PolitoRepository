#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define num_rec 50
#define size 4
#define size_name 30

typedef struct rec
{
    char name[size+1];
    float x1,y1;
    float x2,y2;
} rect_t;

void read_file(char [],rect_t [],int*);
void sort_area(rect_t,int);
void sort_perimeter(rect_t,int);

int main()
{
    rect_t rect[num_rec];
    int n;
    char name1[size_name+1],name2[size_name+1],name3[size_name+1];
    printf("enter files' names\n");
    scanf("%s %s %s",name1,name2,name3);
    read_file(name1,rect,&n);
    printf("Hello world %d!\n",n);
    return 0;
}
/*loading the file content*/
void read_file(char name[],rect_t rect[],int* n)
{
    float x,y;
    int i,flag=0;
    char line[size_name+1];
    char title[size_name+1];
    FILE *fp;
    fp=fopen(name,"r");
    if(fp==NULL)
    {
        fprintf(stderr,"error opening the file");
        exit(1);
    }
    *n=0;
    while(fgets(line,size_name,fp)!=EOF){

        sscanf(line,"%s %f %f",title,&x,&y);
        if(strcmp(title,rect[*n].name)!=0)
        {
            for(i=0; i<*n; ++i)
            {
                if(strcmp(title,rect[i].name)==0)
                {
                    rect[i].x2=x;
                    rect[i].y2=y;
                    flag=1;
                }
            }
        }
        if(flag==0)
        {
            strcpy(rect[*n].name,title);
            rect[*n].x1=x;
            rect[*n].y1=y;
        }
        ++*n;
    }
    for(i=0;i<*n;++i){
        printf("%s   %f  %f",rect[i].name,rect[i].x1,rect[i].y1);
        printf("       %f   %f",rect[i].x2,rect[i].y2);
    }
}
