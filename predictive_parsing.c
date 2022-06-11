#include<stdio.h>
#include<ctype.h>
#include<string.h>

char nt[] = {'E','A','T','B','F'} , ter[]={'i','+','*','(',')','$'};
char arr[20][20][20]={ 
    {"TA"," "," ","TA"," "," "}, 
    {" ","+TA"," "," ","#","#"}, 
    {"FB"," "," ","FB"," "," "}, 
    {" ","#","*FB"," ","#","#"}, 
    {"i"," "," ","(E)"," "," "} 
};
char input[20], stack[20],prod[10];
int i=0,top=1,ia,ix;
void pop();
void push(char );
int resolve_nt(char );
int resolve_t(char );
void advance();

void main(void )
{
    
    char a,x;
    int len,temp,k;
    stack[0] = '$';
    stack[1] = 'E';
    printf("Enter input String(enter '$' as end marker): ");
    scanf("%s",input);
    printf("I/P string\t\tStack\t\tProduction used\n");
    while(1)
    {
        a=input[i];
        x=stack[top];
        for(k=i;input[k]!='$';k++)
        {
            printf("%c",input[k]);
        }
        printf("$\t\t");
        if(x==a)
        {
            if(x=='$')
            {
                printf("\nInput String is accepted..");
                break;
            }
            else
            {
                pop();
                advance();
            }
        }
        else if(isupper(x))
        {
            ix = resolve_nt(x);
            ia = resolve_t(a);
            strcpy(prod,arr[ix][ia]);
            len = strlen(prod);
            pop();
            for(k=1;k<=len;k++){
                push(prod[len-k]);
            }
            if(stack[top]=='#')
                pop();
        }
        else
        {
            printf("\nError: couldnot parse the String..");
            break;
        }
        for(k=0;k<=top;k++)
        {
            printf("%c",stack[k]);
        }
        printf("\t\t%s\n",prod);
    }
}

void push(char t)
{
    stack[++top] = t;
}

void pop()
{
    top--;
}
void advance()
{
    i++;
}
int resolve_t(char t)
{
    int k;
    for(k=0;k<6;k++){
        if(t==ter[k]){
            return k;
        }
    }
}
int resolve_nt(char t)
{
    int k;
    for(k=0;k<5;k++)
    {
        if(nt[k] == t){
            return k;
        }
    }
}
