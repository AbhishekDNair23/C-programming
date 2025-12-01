#include <stdio.h>
struct poly {
    int coeff;
    int expo;
};
int main(){
    int term1,term2,i,j,k;
    struct poly p1[10],p2[10],p3[10];
    
    printf("Enter the number of terms in first polynomial");
    scanf("%d",&term1);
    
    printf("Enter the coefficeint and exponent of terms\n");
    for(i=0;i<term1;i++)
    {
        printf("term %d:",i+1);
        scanf("%d %d",&p1[i].coeff,&p1[i].expo);
    }
    
    printf("Enter the number of terms in second polynomial");
    scanf("%d",&term2);
    
    printf("Enter the coeff and expo of terms \n");
    for(i=0;i<term2;i++)
    {
        printf("term %d",i+1);
        scanf("%d %d",&p2[i].coeff,&p2[i].expo);
    }
    
    i=j=k=0;
    
    while(i<term1&&j<term2)
    {
        if(p1[i].expo == p2[j].expo)
        {
            p3[k].coeff=p1[i].coeff+p2[j].coeff;
            p3[k].expo=p1[i].expo;
            i++;j++;k++;
        }
        else if(p1[i].expo>p2[j].expo)
        {
            p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
        }
        else
        {
            p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            j++;k++;
        }
    }
    while(i<term1)
    {
        p3[k].coeff=p1[i].coeff;
            p3[k].expo=p1[i].expo;
            i++;k++;
    }
    while(j<term2)
    {
        p3[k].coeff=p2[j].coeff;
            p3[k].expo=p2[j].expo;
            j++;k++;
    }
    printf("Resultant polynomial");
    for(i=0;i<k;i++)
    {
        printf("%dx^%d",p3[i].coeff,p3[i].expo);
        if(i<k-1)
        {
            printf("+");
        }
    }

}
