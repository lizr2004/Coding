#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int i,j,k,n,m,fa[2001],c[2001],e[2001],dp[2001][201];
int main()
{
	cin>>n>>m;
	for(i=2;i<=n;i++)cin>>fa[i];
	for(i=1;i<=n;i++)cin>>c[i];
	for(i=1;i<=n;i++)cin>>e[i];
	for(i=n;i>=1;i--)
	{
		for(j=m;j>=c[i];j--)
			dp[i][j]=max(dp[i][j],e[i]);
		for(j=m;j>=0;j--)
			for(k=0;k<=j;k++)
				dp[fa[i]][j]=max(dp[fa[i]][j],dp[fa[i]][j-k]+dp[i][k]);
	}
	int ans=0;
	for(i=0;i<=m;i++)
		if(ans<dp[1][i])ans=dp[1][i];
	cout<<ans<<endl;
	return 0;
}
