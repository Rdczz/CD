#include<stdio.h>
#include<ctype.h>
int main()
{
    int np;
    char prod[20][20],f;
    printf("Enter no of productions: ");
    scanf("%d",&np);
    printf("Enter Grammer: \n");
    for(int i=0;i<np;i++)
    {
        scanf("%s",prod[i]);
    }
    for(int i=0;i<np;i++)
    {
        f = prod[i][0];
        int temp=i;
        if(isupper(prod[i][3]))
        {
            repeat:
            for(int k=0;k<np;k++)
            {
                if(prod[k][0] == prod[i][3])
                {
                    if(isupper(prod[k][3]))
                    {
                        i=k;
                        goto repeat;
                    }
                    else
                    {
                        printf("First(%c) = %c\n",f,prod[k][3]);
                    }
                }
            }
        }
        else
        {
            printf("First(%c) = %c\n",f,prod[i][3]);
        }
        i=temp;
    }
}