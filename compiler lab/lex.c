#include<stdio.h>
#include<ctype.h>
#include<string.h>
void keyword(char str[10])
{
    if(strcmp("while",str)==0||strcmp("for",str)==0||strcmp("do",str)==0||strcmp("int",str)==0||strcmp("char",str)==0||strcmp("float",str)==0||strcmp("double",str)==0||strcmp("switch",str)==0||strcmp("default",str)==0||strcmp("static",str)==0)
        printf("%s is a keyword",str);
    else    
        printf("%s is an identifier",str);
}
int main()
{
    FILE *f1,*f2,*f3;
    char c,str[100],st1[100];
    int num[100],lineco=0,tokenvalue=0,i=0,j=0,k=0;
    f1=fopen("input.txt","r");
    f2=fopen("identifier","w");
    f3=fopen("specialchar","w");
    while(c=getc(f1)!=EOF)
    {
        if(isdigit(c))
        {
            tokenvalue=c-'0';
            c=getc(f1);
            while(isdigit(c))
            {
                tokenvalue*=10+c-'0';
                c=getc(f1);
            }
            num[i++]=tokenvalue;
            ungetc(c,f1);
        }
        else if(isalpha(c))
        {
            putc(c,f2);
            c=getc(f1);
            while(isdigit(c) || isalpha(c) || c=='_' || c=='$')
            {
                putc(c,f2);
                c=getc(f1);
            }
            putc(' ',f2);
            ungetc(c,f1);
        }
        else if(c==' ' || c=='_')
        {
            printf(" ");
        }
        else if(c=='\n')
        {
            lineco++;
        }
        else
        {
            putc(c,f3);
        }
    }
    fclose(f2);
    fclose(f3);
    fclose(f1);
    printf("\nThe nos in the program are:");
    for(j=0;j<i;j++)
    {
        printf("%d",num[j]);
    }
    printf("\n\n");
    f2=fopen("identifier","r");
    k=0;
    while(c=getc(f2)!=EOF)
    {
        if(c!=' ')
        {
            str[k++]=c;
        }
        else
        {
            str[k]='\0';
            keyword(str);
            k=0;
        }
    }
    fclose(f2);
    printf("The special characters are:");
    f3=fopen("specialchar","r");
    while(c=getc(f3)!=EOF)
    {
        printf("%c",c);
    }
    fclose(f3);
    printf("\n The total no of lines are:%d",lineco);
}