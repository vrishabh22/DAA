#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

vector< pair<pair<int,int>, int> > in;
int main()
{
    int i,j,k,x,y,w,z,n;
     cout<<"Enter no. of jobs \n";
     cin>>n;

     cout<<"Enter data in this sequence :- \n";
     cout<<"StartTime\tFinishTime\tWeight(Profit)\n";
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        in.pb(mp(mp(y,x),z));
    }
    sort(in.begin(),in.end());
     int dp[n+1],temp[n+1];
     for(i=0;i<n;i++)
      temp[i]=dp[i]=0;
    dp[0]=in[0].s;
    for(i=1;i<n;i++)
     {
         temp[i]=dp[i]=in[i].s;
         for(j=i-1;j>=0;j--)
           {
                if(in[i].f.s >= in[j].f.f)
                   {
                         dp[i]+=dp[j];
                         temp[i]=dp[i];
                         break;
                   }
           }
           dp[i]=max(dp[i],dp[i-1]);
     }
     x=dp[n-1];
     cout<<"Total Profit is ";
     cout<<dp[n-1]<<endl;
     
     for(i=n-1;i>=0 && x>0;i--)
     {
         if(temp[i]==x)
         {
             cout<<in[i].f.s<<"  "<<in[i].f.f<<endl;
             x-=in[i].s;
         }
     }
    return 0;
}
