#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define line_length 101

typedef struct Nodes
{
    char *line;
    struct Node* next;
} Node;

//typedef struct mat Node;
Node *file_read(int*,char*);
void horizontal(Node*,int);
void vertical(Node*,int);

int main(int argc,char *argv[])
{
    if (argc!=2)
    {
        fprintf(stderr,"error arguments");
        return (EXIT_FAILURE);
    }
    Node *content = NULL;
    int n;
    content=file_read(&n,argv[1]);
    horizontal(content,n);
    //Node *content;
    vertical(content,n);
    // printf("Hello world!\n");
    return 0;
}
/*load the file*/
Node *file_read(int* n,char *name)
{
    FILE *fp;
    Node *content,*p;
    fp=fopen(fp,name);
    if(fp==NULL)
    {
        fprintf(stderr,"error reading file");
        exit(1);
    }
    content=(Node*)malloc(sizeof(Node));
    if(content==NULL)
    {
        fprintf(stderr,"error memory allocation\n");
    }
    content->line=(char*)malloc(line_length*sizeof(char));
    p=content;
    n=0;
    while (fgets(p->line,line_length,fp)!=EOF)
    {
        ++n;
        p->next=(Node*)malloc(sizeof(Node));
        p->next->line=(char*)malloc(line_length*sizeof(char));
        p=p->next;
    }
    return content;
}
/*find the horizontal sequence*/
void horizontal(Node*content,int n)
{
    int i,cnt1,sum=0;
    Node*p=content;
    while(p!=NULL)
    {
        i=0;
        cnt1=0;
        while(i<strlen(p.line))
        {
            i++;
            if(p.line[i]=='h')
            {
                cnt1++;
            }
        }
        if (cnt1==5)
        {
            sum++;
        }
        p=p->next;
    }
    printf("horizontal sequnce= %d",sum);
}
