#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
long long dp[5000];
long long va[5000][1000];
long long POW(int a,int b)
{
	long long ans=1;
	while(b)
	{
		if(b&1)ans*=a;
		a*=a;
		b>>=1;
	}
	return ans;
}
int main()
{
	int a,b;
	int n,m,c;
	while(cin>>n>>m)
	{
		memset(dp,0x3f,sizeof(dp));
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			for(int j=0;j<=n;j++)
				va[i][j]=POW(j,b)*a;
		}
		dp[0]=0;
		for(int i=0;i<m;i++)
			for(int j=n;j>=1;j--)
				for(int k=1;k<=j;k++)
					dp[j]=min(dp[j],dp[j-k]+va[i][k]);
		cout<<dp[n]<<endl;
	}
	return 0;
}  
