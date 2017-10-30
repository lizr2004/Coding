#include <iostream>
#include <stdio.h>
#include <string.h>
int val[2560];
int dp[2560];
int m,n;
int main()
{
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d",&n,&val[0]);
	for(int a=1;a<=n;a++)
	{
		scanf("%d",&val[a]);
		val[a]+=val[a-1];
	}
	// dp[0]=val[0];
	dp[0]=0;
	for(int a=1;a<=n;a++)
		for(int b=a-1;b>=0;b--)
			dp[a]=std::min(dp[b]+val[a-b]+val[0],dp[a]);
	printf("%d\n",dp[n]-val[0]);
	return 0;
}
