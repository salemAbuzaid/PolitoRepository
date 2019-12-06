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
    //read_product_file(s2,head);
    printf("agbgr");
    return 0;
}

producer_t *read_producer_file(char *file_name)
{
    char name[20], id[20];
    int n = 0;
    FILE *fp=NULL;
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
            printf("The size of the struct is %d\n", sizeof(producer_t));
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
            printf("name %s id %s\n", p->name, p->id);
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
            printf("name %s id %s", p->name, p->id);
            printf("basgib\n");
            p->next = NULL;
            p->head_product = NULL;
        }
    }
    printf("n=%d", n);
    fclose(fp);
    return (head);
}
