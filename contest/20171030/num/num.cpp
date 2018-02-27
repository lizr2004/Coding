#include <iostream>
#include <stdio.h>
#include <string.h>
#define MOD 999983
#define aqx

int fuck[100],dp[10240],dp3[10240];
char can[16];bool flag;
int main()
{
	freopen("num.in","r",stdin);
	// freopen("num.out","w",stdout);
	int n;
	scanf("%d%s",&n,can);
	int s=strlen(can);
	for(int a=0;a<s;a++)
	{
		can[a]-='0';
		if(!can[a])flag=1;
	}
	dp[0]=1;
	for(int a=0;a<n;a++)
	{
		if((n-1)==a)memcpy(dp3,dp,sizeof(dp));
		for(int b=9876;b>=0;b--)
		{
			if(!flag) dp[b]=0;
			for(int c=0;c<s;c++)//	C++
			{
				dp[b]+=dp[b-can[c]];
				if(dp[b]>MOD)dp[b]-=MOD;
			}
		}
		if(flag)dp[0]=1;
		// for(int a=0;a<20;a++)
		// 	printf("%d ",dp[a]);
		// puts("");
	}
	int ans=0;
	for(int a=1;a<9876;a++) {
		ans+=(dp[a]*dp[a]);
		if(ans>MOD)ans-=MOD;
	}
	ans*=2;
	// for(int a=0;a<9876;a++) {ans+=(dp2[a]*dp3[a]); if(ans>MOD)ans-=MOD; }
	printf("%d\n",ans%MOD);
}