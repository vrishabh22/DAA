#include<stdio.h>
#include<stdlib.h>
void main()
{
	int sum,j,k;
	printf("Enter n: ");
	int n;
	scanf("%d",&n);
	int a[1000000];
	printf("Enter elements: ");
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int max=a[0];
	for(i=1;i<=n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0;
			for(k=j;k<i+j;k++)
			{
				sum=sum+a[k];
			}
			if(sum>max)
				max=sum;
		}
	}
	for(j=0;j<n;j++){
		printf("%3d",a[j]);
	}

	printf("Max sum is %d\n",max);
}

