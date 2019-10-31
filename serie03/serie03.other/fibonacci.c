#include <stdio.h>


int fibonacci(int k){

    int a=0;
    int b=1;
    int c=0;
    int z;
    
    for(z=0;z<=k;z=z+1){
        c=a+b;
        a=b;
        b=c;
    }
    return b;

    
}

int main(){
    int k=0;
    
    printf("Geben Sie die k-te Stelle für die Fibonacci-Folge ein!\n");
        printf("\n\t k=");
    scanf("%d",&k);
    printf("\n\t Fibonacci=%d\n",fibonacci(k));
    
    return 0;
}
