#include <iostream>
#include <stdio.h>
#include <string.h>
int dp[51200];
int main()
{
	int N,H,now,c;
	scanf("%d%d",&N,&H);
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	while(N--)
	{
		scanf("%d%d",&now,&c);
		for(int a=0;a<=50000;a++)
			dp[a+now]=std::min(dp[a]+c,dp[a+now]);
	}
	// for(int a=0;a<=H+10;a++)
	// 	printf("%d ",dp[a]);
	int ans=0x3f3f3f3f;
	for(int a=H;a<=H+1000;a++)
		ans=std::min(ans,dp[a]);
	printf("%d\n",ans);
	return 0;
}