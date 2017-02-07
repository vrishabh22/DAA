#include<stdio.h>
#include<stdlib.h>
int bubblesort1(int n,int a[])
{
int i,j,counter=0,temp;
for(i=0;i<n-1;i++)
{
	for(j=0;j<n-1-i;j++)
	{
		counter++;
		if(a[j]>a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
return counter;
}

int bubblesort2(int n,int a[])
{
int i,j,counter=0,temp;
for(i=0;i<n-1;i++)
{
	for(j=0;j<n-1-i;j++)
	{
		counter++;
		if(a[j]<a[j+1])
		{
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;
		}
	}
}
return counter;
}

int insertionsort1(int n,int a[])
{
int i,j,counter=0,temp;
for (i=1;i<n;i++) 
{
      temp=a[i];
      j=i-1;
      while((temp<a[j])&&(j>=0)) 
      {
		counter++;
         	a[j+1]=a[j];
         	j=j-1;
      }
      a[j+1]=temp;
}
return counter;
}

int insertionsort2(int n,int a[])
{
int i,j,counter=0,temp;
for (i=1;i<n;i++) 
{
      temp=a[i];
      j=i-1;
      while((temp>a[j])&&(j>=0)) 
      {
		counter++;
         	a[j+1]=a[j];
         	j=j-1;
      }
      a[j+1]=temp;
}
return counter;
}

void main()
{
int sort1(int n,int a[]);
int sort2(int n,int a[]);
int n,a[100000],b[100000],counteravg=0,counterbest=0,counterworst=0;
printf("Enter number of elements in the array: ");
scanf("%d",&n);
printf("Entering the elements of the array randomly: ");
int i,j,temp;
for(i=0;i<n;i++)
{
a[i]=rand();
b[i]=a[i];
}
/*printf("Array is:\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
printf("\n");*/

//insertion sorting
counteravg=insertionsort1(n,a);
counterbest=insertionsort1(n,a);
counterworst=insertionsort2(n,a);
 

/*printf("Sorted array is:\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
printf("\n");*/
printf("\nInsertion Sort\n");
printf("Counter average is %d\n",counteravg);
printf("Counter best is %d\n",counterbest);
printf("Counter worst is %d\n",counterworst);

//bubble sorting
counteravg=bubblesort1(n,b);
counterbest=bubblesort1(n,b);
counterworst=bubblesort2(n,b);
 

/*printf("Sorted array is:\n");
for(i=0;i<n;i++)
printf("%d\n",a[i]);
printf("\n");*/
printf("\nBubble Sort\n");
printf("Counter average is %d\n",counteravg);
printf("Counter best is %d\n",counterbest);
printf("Counter worst is %d\n",counterworst);
}

