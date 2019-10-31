#include <stdio.h>

int geraden(double u[3], double v[3], double s[2]){

    if((u[1]/u[2])==(v[1]/v[2])&&u[3]!=v[3]){
        return 1;
    }
    if((u[1]/u[2]*u[3])==(v[1]/v[2])*v[3]){
        return 0;
    }
    
    if((u[1]/u[2])!=(v[1]/v[2])){   //äquivalenzumformung ergibt x=(ce-fb)/(-db+ae)
        s[1]=(u[3]*v[2]-v[3]*u[2])/(-v[1]*u[2]+u[1]*v[2]);
        s[2]=(u[3]-u[1]*s[1])/u[2];
        return -1;
    }
    
    
    return ;
}

int main(){
    double u[3]={0,0,0};
    double v[3]={0,0,0};
    double s[2]={0,0};
    
    printf("Geben Sie die Werte der Vektoren u und v ein!\n");
        printf("\n\t u[a]=");
    scanf("%lf",&u[1]);
        printf("\n\t u[b]=");
    scanf("%lf",&u[2]);
        printf("\n\t u[c]=");
    scanf("%lf",&u[3]);
        printf("\n\t v[d]=");
    scanf("%lf",&v[1]);
        printf("\n\t v[e]=");
    scanf("%lf",&v[2]);
        printf("\n\t v[f]=");
    scanf("%lf",&v[3]);

    if(geraden(u,v,s)==1){
        printf("Es handelt sich hierbei um zwei parallele Geraden");
    }
    
    if(geraden(u,v,s)==0){
        printf("Es handelt sich hierbei um zwei aufeinanderliegende Geraden");
    }
    
    if(geraden(u,v,s)==-1){
        printf("Diese Geraden schneiden sich im Punkt (%f,%f)",s[1],s[2]);
    }
    
    
    return 0;
}
