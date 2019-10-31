#include <stdio.h>

int binomial(int a, int b){
    if (a == b){
        return 1;
    }
    if (b == 0){
        return 1;
    }
    if(b>a){return 0;}
    return (binomial(a-1, b) + binomial(a-1,b-1));
}


void pascal(int n){
    int x=0;
    int y=0;
    int z=5;
    
    for(x=0;x<n;x++){
        printf("\n");
        for(y=0; y<n;y++){
            if(binomial(x,y)>0){
                printf("%d ",binomial(x,y));
            }

            }
                
            

    }
}

int main(){
    int n=0;

    
    printf("Geben Sie die Größe des pascalschen Dreiecks an!\n");
        printf("\n\t n=");
    scanf("%d",&n);
    pascal(n);

    
    return 0;
}
