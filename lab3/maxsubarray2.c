#include <stdio.h>
#include <limits.h>
 #include<stdlib.h>

int max2(int a, int b) { return (a > b)? a : b; }

int max3(int a, int b, int c) { return max2(max2(a, b), c); }
 
// Find the maximum possible sum in arr[] auch that arr[m] is part of it
int maxCrossingSum(int arr[], int l, int m, int h)
{
    
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--)//start from m and go down till l
    {
        sum = sum + arr[i];
        if (sum > left_sum)
          left_sum = sum;
    }
 
    
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m+1; i <= h; i++)//start from m+1 and go up till h
    {
        sum = sum + arr[i];
        if (sum > right_sum)
          right_sum = sum;
    }
 
    
    return left_sum + right_sum;
}
 

int maxSubArraySum(int arr[], int l, int h)
{
   // Base Case: Only one element
   if (l == h)
     return arr[l];
 
  
   int m = (l + h)/2;
 
   /* Return maximum of following three possible cases
      a) Maximum subarray sum in left half
      b) Maximum subarray sum in right half
      c) Maximum subarray sum such that the subarray crosses the midpoint */
  
  return max3(maxSubArraySum(arr, l, m),
              maxSubArraySum(arr, m+1, h),
              maxCrossingSum(arr, l, m, h));
}
 
int main()
{
   int arr[1000],n;
   printf("Enter n: ");
   scanf("%d",&n);
   printf("Enter array: ");
   int i;
   for(i=0;i<n;i++)
   {
   scanf("%d",&arr[i]);
   }
   int ans=maxSubArraySum(arr,0,n-1);
	printf("Max sum is %d\n",ans);
}
