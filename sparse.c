#include <stdio.h>
int main()
{
    int A[10][10],B[10][10],row1,col1,row2,col2;
    int sp1[10][3],sp2[10][3],spsum[10][3];
    int i,j,k=1,u=1,h=1;
    printf("Enter the rows and cols of mat1");
    scanf("%d%d",&row1,&col1);
    printf("Enter the rows and cols of mat2");
    scanf("%d%d",&row2,&col2);
    if(row1!=row2||col1!=col2)
    {
        printf("Addition is not possible");
        return 0;
    }
    printf("Enter the elements of matrix 1\n");
    for(i=0;i<row1;i++)
    {   
        for(j=0;j<col1;j++)
        {
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter the elements of matrix 2\n");
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
        {
            scanf("%d",&B[i][j]);
        }
    }
    
    for(i=0;i<row1;i++)
    {
        for(j=0;j<col1;j++)
        {
            if(A[i][j]!=0)
            {
                sp1[k][0]=i;
                sp1[k][1]=j;
                sp1[k][2]=A[i][j];
                k++;
            }
        }
    }
    sp1[0][0]=row1;
    sp1[0][1]=col1;
    sp1[0][2]=k-1;
    
    for(i=0;i<row2;i++)
    {
        for(j=0;j<col2;j++)
        {
            if(B[i][j]!=0)
            {
                sp2[h][0]=i;
                sp2[h][1]=j;
                sp2[h][2]=B[i][j];
                h++;
            }
        }
    }
    sp2[0][0]=row2;
    sp2[0][1]=col2;
    sp2[0][2]=h-1;
    
    int p=1,q=1;
    while(p<=sp1[0][2]&&q<=sp2[0][2])
    {
        if(sp1[p][0]<sp2[q][0]||(sp1[p][0]==sp2[q][0]&&sp1[p][1]<sp2[q][1]))
        {
            spsum[u][0]=sp1[p][0];
            spsum[u][1]=sp1[p][1];
            spsum[u][2]=sp1[p][2];
            u++;p++;
        }
        else if(sp2[q][0]<sp2[q][0]||(sp2[p][0]==sp1[p][0]&&sp2[q][1]<sp1[p][1]))
        {
            spsum[u][0]=sp2[q][0];
            spsum[u][1]=sp2[q][1];
            spsum[u][2]=sp2[q][2];
            u++;q++;
        }
        else
        {
            int sumvalue=sp1[p][2]+sp2[q][2];
            if(sumvalue!=0)
            {
                spsum[u][0]=sp1[p][0];
                spsum[u][1]=sp1[p][1];
                spsum[u][2]=sumvalue;
                q++;p++;u++;
            }
        }
    }
    while(p<=sp1[0][2])
    {
        spsum[u][0]=sp1[p][0];
        spsum[u][1]=sp1[p][1];
        spsum[u][2]=sp1[p][2];
        u++;p++;
    }
    while(q<=sp2[0][2])
    {
        spsum[u][0]=sp2[q][0];
        spsum[u][1]=sp2[q][1];
        spsum[u][2]=sp2[q][2];
        u++;q++;
    }
    spsum[0][0]=row1;
    spsum[0][1]=col1;
    spsum[0][2]=u-1;
    printf("Resultant mat");
    printf("row\tcol\tval\t");
    for(i=0;i<u;i++)
    {
        printf("%d\t%d\t%d\n",spsum[i][0],spsum[i][1],spsum[i][2]);
    }
}    
