#include <stdio.h>

//Faktorielle:

int faktorielle(int x){
    if(x==1||x==0){
        return 1;
    }
    else{x=x*(faktorielle(x-1));
    }
    return x;
}

int f(int n, int k){
    if (n == k){
        return 1;
    }
    if (k == 0){
        return 1;
    }
    return (f(n-1, k) + f(n-1,k-1));
}




int binomial(int n, int k, int type){

    if(type==1){
        return faktorielle(n)/(faktorielle(k)*faktorielle(n-k));}
        
    

    if(type==2){
        int b=k;
        int a=0;
        int c=n;
        for (a=1; a<b ;a++){
            k=k*(b-a);
            n=n*(c-a);
        }
        return n/k;

    }
        
        if(type==3){
            return f(n,k);
    }
}

int main(){
    int n=0;
    int k=0;
    int type=0;
    
    
    printf("Geben Sie n und k für den Binomialkoeffizienten ein\n");
        printf("\n\t n=");
    scanf("%d",&n);
        printf("\n\t k=");
    scanf("%d",&k);
        printf("\n\t Typ (1, 2 oder 3)=");
    scanf("%d",&type);
    if (n<k){
            printf("n muss größer als k sein!\n");
    }
    else{
        printf("\n\nDer Binomialkoeffizient beträgt\t\t%d\n\n",binomial(n,k,type));
    }
    
    

    
    
    return 0;
}
