#include "new.h"

void allocat(int***mat,int**used,int** val,int n)
{
    int t=0;
    int **mat_temp = NULL;
    int *used_temp = NULL;
    int *val_temp = NULL;
    mat_temp =(int **)malloc(n*sizeof(int*));
    if(mat_temp == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    for(t=0; t<n; ++t)
    {
        mat_temp[t]=malloc(n*sizeof(int));
        if(mat_temp[t] == NULL)
        {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
    }
    used_temp=(int*)malloc(((n*n)+1)*sizeof(int));
    if(used_temp == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    val_temp=(int*)malloc(n*n*sizeof(int));
    if(val_temp == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    *mat = mat_temp;
    *val = val_temp;
    *used = used_temp;
    return;
}

void fillval(int* val,int* used,int n)
{
    int t=0;
    used[0]=0;
    for(t=1; t<=n*n; ++t)
    {
        val[t-1]=t;
        used[t]=0;
    }
    return;
}

//check matrix
int checkmat(int** mat,int n)
{
    int sum,target,r,c;
    target=n*(n*n+1)/2;
    //check rows
    for(r=0; r<n; ++r)
    {
        sum=0;
        for(c=0; c<n; ++c)
        {
            sum=sum+mat[r][c];
        }
        if(sum!=target)
        {
            return 0;
        }
    }
    //check columns
    for(r=0; r<n; ++r)
    {
        sum=0;
        for(c=0; c<n; ++c)
        {
            sum=sum+mat[c][r];
        }
        if(sum!=target)
        {
            return 0;
        }
    }
    //check the main diagonal
    sum=0;
    for(r=0; r<n; ++r)
    {
        sum=sum+mat[r][r];
    }
    if(sum!=target)
    {
        return 0;
    }
    //check the reverse diagonal
    sum=0;
    for(r=0; r<n; ++r)
    {
        sum=sum+mat[r][n-1-r];
    }
    if (sum!=target)
    {
        return 0;
    }
    return 1;
}
//magic recurrsive function
int magic(int** mat,int *val,int *used,int n,int pos)
{
    int t,r,c;
    r=pos/n;
    c=pos%n;
    if(pos==n*n)
    {
        return(checkmat(mat,n));
    }
    for(t=1; t<=n*n; t++)
    {
        if(used[t]==0)
        {
            used[t]=1;
            mat[r][c]=val[t-1];
            if(magic(mat,val,used,n,pos+1))
            {
                return 1;
            }
        }
            used[t]=0;
    }
    return 0;
}


//printing the matrix
void printmat(int **mat,int n)
{
    int r,c;
    for(r=0; r<n; ++r)
    {
        for(c=0; c<n; ++c)
        {
            printf("%3d",mat[r][c]);
        }
        printf("\n");
    }
}
