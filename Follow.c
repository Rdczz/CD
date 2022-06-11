#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    int np,i,j,k;
    char prod[30][30],fllow[10][10],lmad[10][10];
    printf("Enter no of productions: ");
    scanf("%d",&np);
    printf("Enter grammer: \n");
    for (int i = 0; i < np; i++)
    {
        scanf("%s",&prod[i]);
    }
    for(i=0;i<np;i++)
    {
        if(i==0)
        {
            printf("Follow(%c)=$\n",prod[0][0]);
        }
        for(j=3;prod[i][j]!='\0';j++)
        {
            int temp2 = j;
            if(prod[i][j] >= 'A' && prod[i][j] <= 'Z')
            {
                if((strlen(prod[i])-1)==j)
                {
                    printf("Follow(%c)=Follow(%c)\n",prod[i][j],prod[i][0]);
                }
                int temp = i;
                char f = prod[i][j];
                if(!isupper(prod[i][j+1]) && (prod[i][j+1]!='\0')){
                    printf("Follow(%c) = %c\n",f,prod[i][j+1]);
                }
                if(isupper(prod[i][j+1]))
                {
                    repeat:
                    for(k=0;k<np;k++)
                    {
                        if(prod[k][0]==prod[i][j+1])
                        {
                            if(!isupper(prod[k][3]))
                            {
                                printf("Follow(%c)=%c\n",f,prod[k][3]);
                            }
                            else{
                                i=k;
                                j=2;
                                goto repeat;
                            }
                        }
                    }
                }
                i=temp;
            }
            j=temp2;
        }
    }
}