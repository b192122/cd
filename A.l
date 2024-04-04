%{
#include<stdio.h>
int length;
%}
%%
[a-zA-Z0-9]+ {length=yyleng;fun(length);}
%%
fun(int l)
{
if(yytext[0]=='A'){
if(length==3){
printf("%s is of length of 3",yytext);
}
}
}
int yywrap(){
return 1;
}
int main()
{
yylex();
return 0;
}