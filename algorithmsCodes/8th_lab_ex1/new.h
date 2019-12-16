#ifndef _NEW
#define _NEW
#include <stdlib.h>
#include <stdio.h>
void allocat(int***mat,int**used,int** val,int n);
void fillval(int* val,int* used,int n);
int magic(int** mat,int *val,int *used,int n,int pos);
int checkmat(int** mat,int n);
void printmat(int **mat,int n);
#endif
