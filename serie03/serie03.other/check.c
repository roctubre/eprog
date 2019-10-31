#include <stdio.h>


int check(int x[10],int y[3]){
    int a=1;
    
    for (a=0;a<8;a++){
        if(y[0]==x[a] && y[1]==x[a+1] && y[2]==x[a+2]){
            return 1;                               }
        }
    for (a=1;a<=10;a++){
        if(y[1]!=x[a] || y[2]!=x[a] || y[3]!=x[a]){
            return 0;                               }
        }
    }


int main(){
    int x[10]={0,0,0,0,0,0,0,0,0,0};
    int y[3]={0,0,0};
    int h=0;

    printf("Geben Sie die 10 Werte für x ein!\n");
        printf("\n\t x[1]=");
    scanf("%d",&x[0]);
        printf("\n\t x[2]=");
    scanf("%d",&x[1]);
        printf("\n\t x[3]=");
    scanf("%d",&x[2]);
        printf("\n\t x[4]=");
    scanf("%d",&x[3]);
        printf("\n\t x[5]=");
    scanf("%d",&x[4]);
        printf("\n\t x[6]=");
    scanf("%d",&x[5]);
        printf("\n\t x[7]=");
    scanf("%d",&x[6]);
        printf("\n\t x[8]=");
    scanf("%d",&x[7]);
        printf("\n\t x[9]=");
    scanf("%d",&x[8]);
        printf("\n\t x[10]=");
    scanf("%d",&x[9]);
        printf("\n Geben Sie nun die Werte für y ein!");
        printf("\n\t y[1]=");
    scanf("%d",&y[0]);
        printf("\n\t y[2]=");
    scanf("%d",&y[1]);
        printf("\n\t y[3]=");
    scanf("%d",&y[2]);
    
    for (h=0;h<3;h++){
        printf("%d",y[h]);
    }
    
    
    printf("\n\n%d",check(x,y));

    
    return 0;
}
