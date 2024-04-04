%{
#include<stdio.h>
int numofint=0,numoffloat=0;
%}
%%
[0-9]+"."[0-9]+ {ECHO;printf("\nDecimal Number\n");numoffloat++;}
[0-9]+ {ECHO;printf("\nInteger Number\n");numofint++;}
%%
int yywrap()
{return 1;}
int main()
{
yylex();
printf("Number of Decimal Numbers:%d\nnumber of Integer Numbers:%d",numoffloat,numofint);
return 0;
}