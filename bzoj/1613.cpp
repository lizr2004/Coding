#include <iostream>
#include <stdio.h>

int dp[10240][512];

int main(int argc, char const *argv[])
{
	int N,M;
	scanf("%d%d",&N,&M);
	for(int n=1;n<=N;n++)
	{
		int now;
		scanf("%d",&now);
		for(int i=1;i<=M;i++)
			dp[n][i]=dp[n-1][i-1]+now;
		dp[n][0]=dp[n-1][0];
		for(int i=1;i<=M;i++)
			if(n>i)
				dp[n][0]=std::max(dp[n-i][i],dp[n][0]); 
	}
	printf("%d\n",dp[N][0]);
	return 0;
}