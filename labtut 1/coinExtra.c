#include <stdio.h>
int main()
{
	int n,nc,i,c[10];
	printf("Enter change amount : ");
	scanf("%d",&n);
	printf("Enter number of coins : ");
	scanf("%d",&nc);
	int a[nc];
	printf("Enter value of each coin \n");
	for(i=1;i<=nc;i++)
		scanf("%d",&a[i]);
	int j=1;
	printf("*******************\n");
	for ( i = nc; i >= 0; i--)
		if(n>=a[i] && (n!=0))
		{
			c[j]=n/a[i];
			n%=a[i];
			printf("%d paise :- %d coin \n",a[i],c[j]);
			j++;
		}
	return 0;
}
