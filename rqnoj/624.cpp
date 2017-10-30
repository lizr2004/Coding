#include <iostream>
#include <string.h>
#include <vector>
#include <stdio.h>
using namespace std;
struct shoe{int sh,wo;};
vector<shoe> sho[105];
int tots[105];
int dp[105][10005];
int n,m,k,t,t1,t2;
int main()
{
	cin>>n>>m>>k;
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int a=0;a<n;a++)
	{
		cin>>t>>t1>>t2;
		sho[t].push_back((shoe){t1,t2});
	}
	for(int a=1;a<=k;a++)
	{
		int sz=sho[a].size();
		for(int b=0;b<sz;b++)
			for(int c=m;c>=sho[a][b].sh;c--)
			{
				if(dp[ a ][c-sho[a][b].sh]!=-1)
					dp[a][c]=max(dp[a][c],dp[ a ][c-sho[a][b].sh]+sho[a][b].wo);
				if(dp[a-1][c-sho[a][b].sh]!=-1)
					dp[a][c]=max(dp[a][c],dp[a-1][c-sho[a][b].sh]+sho[a][b].wo);
			}
	}
	int ans=-1;
	for(int a=0;a<m;a++)
		ans=max(ans,dp[k][a]);
	if(ans==-1)puts("Impossible");
	else cout<<ans<<endl;
}