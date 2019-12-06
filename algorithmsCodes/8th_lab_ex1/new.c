#include <stdlib.h>
#include "new.h"


void allocat(int***mat,int n){
    int t=0;
    *mat =(int **)malloc(n*sizeof(int*));
    for(t=0; t<n;++t){
        (*mat)[t]=malloc(n*sizeof(int));
    }
}
