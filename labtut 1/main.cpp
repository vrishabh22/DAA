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
int memo[10];
int calc(int i)
{
     if(i<0)
        return 0;
    if(memo[i]!=-1)
     return (memo[i]);
     memo[i]=in[i].s;
     for(int j=i-1;j>=0;j--)
        if (in[i].f.s >= in[j].f.f)
          {
              memo[i]+=calc(j);
              break;

          }
          memo[i]=max(memo[i],calc(i-1));
       return (memo[i]);   
}
int main()
{
     int i,j,k,x,y,w,z,n;
     cin>>n;
     for(i=0;i<10;i++)
       memo[i]=-1;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        in.pb(mp(mp(y,x),z));
    }
    sort(in.begin(),in.end());
    int ans=-1;
    for(i=n-1;i>=0;i--)
      ans=max(ans,calc(i));
    cout<<ans<<endl;
    return 0;
}
