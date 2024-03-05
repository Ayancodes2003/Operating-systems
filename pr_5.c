#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
char str[100],ch;
int i,ctr;



printf("input the string\n");
fgets(str,sizeof str,stdin);



ctr=strlen(str);
printf("the given sentence is %s",  str);
printf("after case change in the string ");


for(i=0;i<ctr;i++)
{
ch=islower(str[i])?toupper(str[i]):tolower(str[i]);
printf("%c",ch);
}
printf("\n");

}
