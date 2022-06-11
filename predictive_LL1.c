#include<stdio.h>
#include<string.h>
#include<process.h>

char prod[20][20],start[2];
char nonterm[20],term[20];
char input[10],stack[50];
int table[10][10];
int te,nte,np;

void init();
void parse();
void main()
{
    init();
    parse();
}

void init()
{
    int i,j;
    printf("Enter no of Terminals: ");
    scanf("%d",&te);
    for(i=0;i<te;i++)
    {
        printf("Enter terminal %d: ",i+1);
        scanf(" %c",&term[i]);
    }
    term[i]='$';
    printf("Enter no of non terminals: ");
    scanf("%d",&nte);
    for(i=0;i<nte;i++)
    {
        printf("Enter non-terminal %d: ",i+1);
        scanf(" %c",&nonterm[i]);
    }
    printf("Enter no of productions: ");
    scanf("%d",&np);
    printf("Enter Grammer: \n");
    for(i=0;i<np;i++)
    {
        scanf("%s",prod[i]);
    }
    start[0] = prod[0][0];
    printf("Enter input string: ");
    scanf("%s",input);
    printf("The grammer is : \n");
    for(int i=0;i<np;i++)
    {
        printf("%d\t%s\n",i+1,prod[i]);
    }
    printf("Enter Parsing table: \n");
    for(int i=0;i<nte;i++)
    {
        for(int j=0;j<=te;j++)
        {
            printf("Enter the Entry for table[%c][%c]: ",nonterm[i],term[j]);
            scanf("%d",&table[i][j]);
        }
    }
}

void parse()
{
    int i,j,prodno;
    int top=-1,cur=0;
    stack[++top] = '$';
    stack[++top] = start[0];
    do{
        if((stack[top]==input[cur]) && (input[cur]=='$'))
        {
            printf("\nThe given input string is parsed");
            exit(0);
        }
        else if(stack[top]==input[cur])
        {
            top--;
            cur++;
        }
        else if(stack[top]>='A' && stack[top]<= 'Z')
        {
            for(i=0;i<nte;i++)
            {
                if(nonterm[i]==stack[top])
                    break;
            }
            for(j=0;j<=te;j++)
            {
                if(term[j]==input[cur])
                    break;
            }
            prodno = table[i][j];
            if(prodno == 0)
            {
                printf("\nThe input String is not parsed..");
                exit(0);
            }
            else
            {
                for(i=strlen(prod[prodno-1])-1;i>=3;i--)
                {
                    if(prod[prodno-1][i]!='@')
                        stack[top++] = prod[prodno-1][i];
                }
                top--;
            }
        }
        else{
            printf("\nThe input String is not parsed..");
            exit(0);
        }
    }while(1);
}