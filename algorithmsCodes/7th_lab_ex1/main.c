#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

int main()
{
    char s1[50] = {'\0'};
    char s2[50] = {'\0'};
    producer_t *head = NULL;
    printf("enter the two files' names\n");
    scanf("%s %s", s1, s2);
    head = read_producer_file(s1);
    read_product_file(s2, head);
    print_t(head);
    dispose(head);

    return 0;
}

producer_t *read_producer_file(char *file_name)
{
    char name[20], id[20];
    int n = 0;
    FILE *fp = NULL;
    producer_t *p = NULL;
    producer_t *head = NULL;
    fp = fopen(file_name, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "error reading the file");
        exit(1);
    }
    while (fscanf(fp, "%s %s", name, id) != EOF)
    {
        ++n;
        if (head == NULL)
        {
            // printf("The size of the struct is %d\n", sizeof(producer_t));
            head = (producer_t *)malloc(sizeof(producer_t));
            if (head == NULL)
            {
                fprintf(stderr, "error of allocation memory");
                exit(1);
            }
            head->next = NULL;
            head->head_product = NULL;
            p = head;
            //sscanf(line,"%s %s",p->name,p->id);
            p->name = (char *)malloc(sizeof(char) * strlen(name));
            p->id = (char *)malloc(sizeof(char) * strlen(id));
            strcpy(p->name, name);
            strcpy(p->id, id);
            //printf("name %s id %s\n", p->name, p->id);
        }
        else
        {
            // printf("The pointer of P is %p\n",p);
            p->next = (producer_t *)malloc(sizeof(struct producer));
            if (p->next == NULL)
            {
                fprintf(stderr, "alloction cderror\n");
                exit(1);
            }
            p = p->next;
            //sscanf(line,"%s %s",p->name,p->id);
            p->name = (char *)malloc(sizeof(char) * strlen(name));
            p->id = (char *)malloc(sizeof(char) * strlen(id));
            strcpy(p->name, name);
            strcpy(p->id, id);
            //printf("name %s id %s", p->name, p->id);
            //printf("basgib\n");
            p->next = NULL;
            p->head_product = NULL;
        }
    }
    //printf("n=%d", n);
    fclose(fp);
    return (head);
}

void read_product_file(char *name, producer_t *head)
{
    char id[20] = {'\0'};
    char type[20] = {'\0'};
    float price = 0;
    producer_t *ptr;
    product_t *p;
    FILE *fp = NULL;
    fp = fopen(name, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "error opening the file 2");
    }
    while (fscanf(fp, "%s %s %f", id, type, &price) != EOF)
    {
        for (ptr = head; ptr != NULL; ptr = ptr->next)
        {
            if (strcmp(id, ptr->id) == 0)
            {
                if (ptr->head_product == NULL)
                {
                    ptr->head_product = malloc(sizeof(product_t));
                    strcpy(ptr->head_product->id, id);
                    strcpy(ptr->head_product->type, type);
                    ptr->head_product->price = price;
                    p = ptr->head_product;
                    p->next = NULL;
                }
                else
                {
                    p->next = malloc(sizeof(product_t));
                    p = p->next;
                    p->next = NULL;
                    strcpy(p->id, id);
                    strcpy(p->type, type);
                    p->price = price;
                    printf("id %s type %s price %f",p->id,p->type,p->price);
                }

            }
        }
    }

    return;
}



void print_t(producer_t *head)
{
    char name[20];
    producer_t *ptr = NULL;
    product_t* p;
    printf("enter the name of the product and press stop to end\n");
    scanf("%s",name);
    while (strcmp(strlwr(name), "stop") != 0)
    {
        for(ptr=head;ptr!=NULL;ptr=ptr->next){
            if(strcmp(strlwr(name),strlwr(ptr->name))==0){
                printf("the id %s\n",ptr->id);
                for(p=ptr->head_product;p !=NULL;p=p->next){
                    printf("type %s price %f\n",p->type,p->price);
                }
            }
        }
        scanf("%s",name);
    }

    return;
}


void dispose(producer_t* head){
    producer_t* ptr=NULL;
    product_t *p=NULL;
    for(ptr=head;ptr!=NULL; ptr=ptr->next){
        for(p=ptr->head_product;p!=NULL;p=p->next){
            free(p);
        }
        free(ptr);
    }

    return;
}
