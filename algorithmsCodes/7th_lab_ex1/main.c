#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct product
{
    char *id;
    char *type;
    float price;
    struct product *next;
} product_t;

typedef struct producer
{
    char *name;
    char *id;
    struct producer *next;
    product_t* head_product;
} producer_t;

producer_t* read_producer_file(char *);
void read_product_file(char *,producer_t *);

int main()
{
    char s1[50],s2[50];
    producer_t *head;
    printf("enter the two files' names\n");
    scanf("%s %s",s1,s2);
    head =read_producer_file(s1);
    //read_product_file(s2,head);
    printf("agbgr");
    return 0;
}

producer_t* read_producer_file(char *file_name)
{
    char name[20],id[20];
    int n=0;
    FILE*fp;
    fp=fopen(file_name,"r");
    if(fp==NULL)
    {
        fprintf(stderr,"error reading the file");
        exit(1);
    }
    producer_t* p,*head=NULL;
    while(fscanf(fp,"%s %s",name, id)!=EOF)
    {
        ++n;
        if(head==NULL)
        {
            head=malloc(sizeof(producer_t));
            if(head ==NULL){
                fprintf(stderr,"error of allocation memory");
                exit(1);
            }
            head->next =NULL;
            head->head_product=NULL;
            p=head;
            //sscanf(line,"%s %s",p->name,p->id);
            strcpy(p->name,name);
            strcpy(p->id,id);
            printf("name %s id %s\n",p->name,p->id);
        }
        if(head!=NULL)
        {
            p->next=malloc(sizeof(producer_t));
            if(p->next==NULL){
                fprintf(stderr,"alloction error\n");
                exit(1);
            }
            p=p->next;
            //sscanf(line,"%s %s",p->name,p->id);
            strcpy(p->name,name);
            strcpy(p->id,id);
            printf("name %s id %s",p->name,p->id);
            printf("basgib\n");
            p->next =NULL;
            p->head_product=NULL;
        }
    }
    printf("n=%d",n);
    fclose (fp);
    return (head);
}


