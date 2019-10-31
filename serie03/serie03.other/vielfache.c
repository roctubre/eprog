#include <stdio.h>


void vielfache(int k, int nmax){

    int a=(nmax-nmax%k)/k;
    int x;
    
    for (x=0;x<=a;x++){
        printf("%d x %d = %d\n",x,k,x*k);
    }
}

int main(){
    int k=0;
    int nmax=0;
    
    
    printf("Geben Sie die Zahl für nmax und die Zahl für k ein.\n");
        printf("\n\t k=");
    scanf("%d",&k);
        printf("\n\t nmax=");
    scanf("%d",&nmax);
    vielfache(k, nmax);

    
    return 0;
}
