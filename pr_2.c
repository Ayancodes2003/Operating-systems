#include<stdio.h>
int n;
struct student{
 int regno;
 char na[50];
 char br[50];
 char dob[10];
 int ma[5];
 char gr;
};
int main()
{
printf("enter the number of students\n");
scanf("%d",&n);
struct student st[n];
for(int i=0;i<n;i++)
{
    printf("enter student registration number\n");
    scanf("%d",&st[i].regno);
    printf("enter student name\n");


    scanf("%s",st[i].na);
    printf("enter student branch\n");
    scanf("%s",st[i].br);
    printf("enter date of birth (dd-mm-yyyy)\n");
    scanf("%s",st[i].dob);
    printf("enter 5 subject marks\n");
    for(int j=0;j<5;j++)
    {
        scanf("%d",&st[i].ma[j]);
    }
    int tm=0;
    for(int j=0;j<n;j++)
    {
        tm+=st[i].ma[j];
    }
    float am=tm/n;
    if(am>90)
    st[i].gr='S';
    else if(am>80)
    st[i].gr='A';
    else if(am>70)
    st[i].gr='B';
    else if(am>60)
    st[i].gr='C';
    else
    st[i].gr='F';
}
printf("students details\n");
for(int i=0;i<n;i++)
{
printf("details of student %d\n",i+1);
printf("registration number %d\n",st[i].regno);
printf("name %s\n",st[i].na);
printf("branch %s\n",st[i].br);
printf("date of birth %s\n",st[i].dob);
for(int j=0;j<5;j++)
printf("subject %d marks are %d\n",j+1,st[i].ma[j]);
printf("student grade is %c\n",st[i].gr);
}
return 0;
}
