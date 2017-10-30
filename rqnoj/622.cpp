#include <iostream>
#include <string.h>
using namespace std;

int dp[100][10000];
int c[100][100];
int w[100][100];
int n,m,d;

int main()
{
	cin>>n>>m>>d;
	for(int a=1;a<=n;a++)for(int b=1;b<=m;b++)cin>>c[a][b];
	for(int a=1;a<=n;a++)for(int b=1;b<=m;b++)cin>>w[a][b];
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int a=1;a<=n;a++)
		for(int b=1;b<=m;b++)
			for(int x=d;x>=c[a][b];x--)
				dp[a][x]=min(dp[a][x],w[a][b]+dp[a-1][x-c[a][b]]);
	int ans=0x3f3f3f3f;
	for(int a=1;a<=d;a++)
		ans=min(ans,dp[n][a]);
	cout<<ans<<endl;
}