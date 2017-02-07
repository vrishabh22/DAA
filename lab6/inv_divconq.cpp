#include <bits/stdc++.h>

int s;

void merge(int a[],int l,int u,int m) {	
	int i,j;
	int n1,n2;
	n1=m-l+1;
	n2=u-m;
	int left[n1],right[n2];
	for(i=0;i<n1;i++)
		left[i]=a[l+i];
	for(i=0;i<n2;i++)
		right[i]=a[m+1+i];

	int k=l;
	i=0;
	j=0;
	while(i<n1 && j<n2) {
		if(left[i]<=right[j])
			a[k++]=left[i++];
		else {	
			a[k++]=right[j++];
			s+=n1-i;
		}
	}
	if(i<n1) {	
		while(i<n1)
			a[k++]=left[i++];
	}
	else if(j<n2) {	
		while(j<n2)
			a[k++]=right[j++];
	}

}

void sort(int a[],int l,int u) {	
	if(l<u) {	
		int m=(l+u)/2;
		sort(a,l,m);
		sort(a,m+1,u);
		merge(a,l,u,m);
	}

}

main() {	
	int a[100],n,i,m;
	printf("Enter value of n\n->");
	scanf("%d",&n);
	printf("Enter array\n->");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	sort(a,0,n-1);
	// printf("Sorted array: ");
	// for(i=0;i<n;i++)
	// 	printf("%d ",a[i]);
	
	printf("\nNumber of inversions\n->");
	printf("%d\n",s);
}
