#include <iostream>
using namespace std;
int n,m,T,c[1005],w[1005],dp[1005][1005];
int main()
{
    cin>>n>>m>>T;
	for(int i=1;i<=n;i++)
		cin>>c[i]>>w[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=T;j++)
			if(i==0)
				dp[i][j]=0;
			else
				dp[i][j]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		for(int j=m;j>=1;j--)
			for(int k=T;k>=c[i];k--)
				dp[j][k]=max(dp[j][k],dp[j-1][k-c[i]]+w[i]);
	if(dp[m][T]<0)
		cout<<0;
	else
		cout<<dp[m][T];
}