#include <stdio.h>
#include <iostream>
using namespace std;
int dp[110][221];
int b[10010];
int n,v,k,a;
int main()
{
	cin>>n>>v>>k;
	for(int i=n-1;i>=1;i--)
		cin>>b[i];
	for(int i=1;i<n;i++)
	{
		a=b[i];
		if(i==1)
		{
			if(a<=v&&(v-a)<=k)
				dp[1][v]=v;
			else
			{
				puts("YI DING YAO JIAN CHI JI HUA SHENG YU");
				return 0;
			}
			continue;
		}
		for(int j=0;j<201;j++)
		{
			if(j>=a&&j<=a+k)
				dp[i][j]=max(dp[i-1][j+1],max(dp[i-1][j-1],dp[i-1][j]));
			else
				dp[i][j]=0;
			if(dp[i][j]!=0)
				dp[i][j]+=j;
		}
	}
	int maxx=0;
	for(int i=0;i<201;i++)
		maxx=max(maxx,dp[n-1][i]);
	if(maxx==0)puts("YI DING YAO JIAN CHI JI HUA SHENG YU");
	else printf("%.2f\n",maxx*(n-1.0));
}
