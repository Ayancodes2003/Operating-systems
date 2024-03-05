#include<stdio.h>
int main()
{

int i,f=1,num;    

 printf("enter a number ");    
  scanf("%d",&num);    
    for(i=1;i<=num;i++)

  {    
      f=f*i;    
  }    

  printf("factoriaL of %d is %d\n",num,f);    
return 0;



}
