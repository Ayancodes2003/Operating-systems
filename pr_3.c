#include<stdio.h>
int main()  
{    
      
int a[100],i,j;
int n;
printf("enter no of elements");
scanf("%d",&n);


printf("enter the elements");
for(int i=0;i<n;i++) 
scanf("%d",&a[i]);





printf("Duplicate elements in given array: \n");
for(int i=0;i<n;i++) 
{    
    printf("\n%d positioned at %d and",a[i],i+1);
    for(int j=i+1;j<n; j++) 
    {    
            if(a[i]==a[j])    
            {
                printf("%d,",j+1);    
            }    
    }    
    return 0;    
}  
}
