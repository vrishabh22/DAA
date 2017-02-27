#include<stdio.h>
main()
{
int a[]={1,5,10,25};
int n=4,i;
/*
printf("n->\n");
scanf("%d",&n);
int a[n];
printf("----\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);

}

*/
int p=0;
printf("p->");
scanf("%d",&p);

i=n-1;

int d=0;
while(p>=0 && i>=0)
{
//int d=0;

if(p>=a[i])
{
d=p-a[i];
p=d;
printf("%d\n",a[i]);
}
else
{
i--;}
//i--;
}}
