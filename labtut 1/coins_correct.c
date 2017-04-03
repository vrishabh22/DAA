#include<stdio.h>

 
// m is size of coins array (number of different coins)
int minCoins(int coins[], int m, int V)
{
   // base case
   if (V == 0) return 0;
 
   // Initialize result
   int res = 999;
 
   // Try every coin that has smaller value than V
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         int sub_res = minCoins(coins, m, V-coins[i]);
 
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         if (sub_res != 999 && sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
}
 
// Driver program to test above function
int main()
{
    int coins[100],m,i,V;
    printf("Enter number of coins: ");
    scanf("%d",&m);
    printf("Enter denomination of coins in descending order: ");
    for(i=0;i<m;i++)
        scanf("%d",&coins[i]);	  		
    //int m = sizeof(coins)/sizeof(coins[0]);
    printf("Enter value: ");
    scanf("%d",&V);
    printf("Minimum coins required is %d\n",minCoins(coins, m, V));
    return 0;
}
