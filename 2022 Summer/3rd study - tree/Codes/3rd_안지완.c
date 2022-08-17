#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    int k;
    int *p;
    scanf(" %d",&k);
    p = (int*)malloc(sizeof(int)*(pow(2,k)));
    for(int i = 0 ; i < pow(2,k)-1; i++){
        scanf(" %d",(p+i));
    }

    int i;
    for(int j = k ; j > 0 ; j--){
        i = pow(2,j-1)-1;
        while(i < pow(2,k)){
            printf("%d ", p[i]);
            i += pow(2,j);
        }
        printf("\n");
    }

}