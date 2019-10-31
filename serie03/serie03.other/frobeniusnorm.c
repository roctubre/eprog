#include <stdio.h>
#include <math.h>

int main(){
    int a=0;
    int b=0;
    int m=0;
    int n=0;
    double z=0;
    
printf("Geben Sie die Dimensionen für die Matrix A ein!\n");
        printf("\n\t Zeilen m=");
    scanf("%d",&m);
        printf("\n\t Spalten n=");
    scanf("%d",&n);
        
    int A[m][n];

    
    for(a=1;a<=m;a++){
        for(b=1; b<=n; b++){
            printf("\nGeben Sie den Wert für die %d-te Zeile und %d-te Spalte ein!\n\t",a,b);
            scanf("%d",&A[a][b]);
        }
    }
    
    for(a=1;a<=m;a++){
        printf("\n");
        for(b=1; b<=n; b++){
            printf(" %d ",A[a][b]);
        }
    }

        for(a=1;a<=m;a++){
            for(b=1; b<=n; b++){
                A[a][b]=pow(A[a][b],2);
                z=z+A[a][b];
    
        }}

            z=sqrt(z);
            printf("\n\n\tDas Ergebnis ist %lf\n",z);
    
    
    return 0;
}
