#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long n,m;
long long dp[110000];
long long t[110000],x[110000],y[110000];
long long ans;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>t[i]>>x[i]>>y[i];
		dp[i]=1;
	}
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<i;j++)
			if((abs(x[i]-x[j])+abs(y[i]-y[j]))<=(t[i]-t[j]))
				dp[i]=max(dp[i],dp[j]+1);
		ans=max(ans,dp[i]);
	}
	printf("%lld\n",ans);
}
