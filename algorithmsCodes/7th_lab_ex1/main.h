#ifndef _header_
#define _header_


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


#endif