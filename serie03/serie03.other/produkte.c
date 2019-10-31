#include <stdio.h>

double skalarProdukt(double u[3], double v[3])      {
    double w=u[1]*v[1]+u[2]*v[2]+u[3]*v[3];
    return w;                                       }



void vektorProdukt(double u[3], double v[3], double w[3]){
    w[1]=u[2]*v[3]-u[3]*v[2];
    w[2]=u[3]*v[1]-u[1]*v[3];
    w[3]=u[1]*v[2]-u[2]*v[1];
    printf("\n\n\tDas Vektorprodukt ergibt folgende Einträge:\nw[1]=\t%f  \nw[2]=\t%f \nw[3]=\t%f\n\n",w[1],w[2],w[3]);
}




int main(){
    double u[3]={0,0,0};
    double v[3]={0,0,0};
    double w[3]={0,0,0};
    
    printf("Geben Sie die Werte der Vektoren u und v ein!\n");
        printf("\n\t u[a]=");
    scanf("%lf",&u[1]);
        printf("\n\t u[b]=");
    scanf("%lf",&u[2]);
        printf("\n\t u[c]=");
    scanf("%lf",&u[3]);
        printf("\n\t v[x]=");
    scanf("%lf",&v[1]);
        printf("\n\t v[y]=");
    scanf("%lf",&v[2]);
        printf("\n\t v[z]=");
    scanf("%lf",&v[3]);
    
    printf("\n\nDas Skalarprodukt lautet %f",skalarProdukt(u,v));
    vektorProdukt(u,v,w);
    
    return 0;
}
