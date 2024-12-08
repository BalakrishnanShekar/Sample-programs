%{
#include<stdio.h>
int vow=0,cons=0;
%}
%%
[\t\n]+ ;
[aeiouAEIOU] {vow++;}
[^aeiouAEIOU] {cons++;}
%%
int main()
{
printf("Enter the string:");
yylex();
printf("There are %d no of vowels",vow);
printf("\n");
printf("There are %d no of consonants",cons);
}
int yywrap()
{
    return 1;
}