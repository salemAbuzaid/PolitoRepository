#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define w_length 50

typedef struct list
{
    char *word;
    int frequency;
    struct list *next;
} list_t;

list_t *read_file(char[]);
list_t *alloc(int);
void print_file(list_t*,char*);
void free_list(list_t* head);
/*the main function*/
int main(int argc ,char* argv[])
{

    list_t *head;
    if(argc !=3)
    {
        fprintf(stderr,"error of number arguments\n");
        exit(1);
    }
    head=read_file (argv[1]);
    printf("Hello world!\n");
    print_file(head,argv[2]);
    free_list(head);
    //printf("Hello world!\n");
    return 0;
}

/*load the file*/
list_t *read_file(char name[])
{
    //printf("%s",name);
    char word[w_length];
    list_t *p,*tmptr1,*head=NULL;
    FILE* fp;
    fp=fopen(name,"r");
    if(fp==NULL)
    {
        fprintf(stderr,"error openning the file input");
        exit(1);
    }
    //head =alloc();
    //printf("%p",head);
    //p=head;
    //fscanf(fp,"%s",word);
    //strcpy(p->word,word);
    //p->frequency++;
    // printf("%s",p->word);
    int flag=0;
    while (fscanf(fp,"%s",word)!=EOF)
    {
        int flag=0;
        if(head==NULL)
        {
            printf("Hellllllo world %p!\n",head);
            head=alloc(strlen(word+1));
            strcpy(head->word,word);
            head->frequency++;
            head->next=NULL;
            printf("Hellllllo world %s!\n",head->word);
        }
        else
        {
            for(tmptr1=head; flag==0, tmptr1!=NULL; tmptr1=tmptr1->next)
            {
                if(strcmp(strlwr(word),strlwr(tmptr1->word))==0)
                {
                    tmptr1->frequency++;
                    flag=1;
                    printf("flag=%d %d\n",flag,strcmp(strlwr(word),strlwr(tmptr1->word)));
                }
            }
        //printf("flag=%d\n",flag);

         if(flag==0){
            p=alloc(strlen(word)+1);
            strcpy(p->word,word);
            p->frequency++;
            p->next=head;
            head=p;
            //printf("entered if %d!\n",flag);
         }
       // printf("%s\n",head->word);
        }
    }
    fclose(fp);
    return head;
}
/*allocate the file*/
list_t *alloc(int word_length)
{
    list_t *head;
    head =malloc(sizeof(list_t));
    if (head ==NULL)
    {
        fprintf(stderr,"error allocation\n");
        exit(1);
    }
    head->word=malloc(word_length*sizeof(char));
    if(head->word==NULL)
    {
        fprintf(stderr,"error allocation\n");
        exit(1);
    }
    //head->next=NULL;
    head->frequency=0;
    return head;
}

/*printing the results*/
void print_file(list_t* head,char name[])
{
    FILE *fp;
    fp=fopen(name,"w");
    if(fp==NULL)
    {
        fprintf(stderr,"error opening the file output");
        exit(1);
    }
    list_t *p;
    p=head;
    while(p!=NULL)
    {
        fprintf(fp,"%s   occurance %d\n",p->word,p->frequency);
        p=p->next;
    }
    fclose(fp);
}

/*freeing the memory*/
void free_list(list_t* head)
{
    list_t *temp,*p=head;
    while(p!=NULL)
    {
        temp=p;
        free(p->word);
        free(p);
        p=temp->next;
    }
}
