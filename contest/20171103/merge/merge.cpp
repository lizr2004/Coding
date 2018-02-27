#include <iostream>
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f
int dp[4999][4999];
int main()
{
	freopen("merge.in","r",stdin);
	freopen("merge.out","w",stdout);
	int n,m,k;
	memset(dp,0x3f,sizeof(dp));
	scanf("%d%d%d",&n,&m,&k);
	while(m--)
	{
		int st,en,va;
		scanf("%d%d%d",&st,&en,&va);
		dp[st][en]=va;
	}
	for(int a=1;a<=n;a++)
	for(int b=1;b<=n;b++)
	for(int c=1;c<=n;c++)
	{
		int &ab=dp[a][b]; int &bc=dp[b][c]; int &ac=dp[a][c];
		if(ab==INF && ac!=INF && bc!=INF)ab=ac-bc;
		if(ac==INF && ab!=INF && bc!=INF)ac=ab+bc;
		if(bc==INF && ac!=INF && ab!=INF)bc=ac-ab;
	}
	while(k--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(dp[a][b]==INF)puts("UNKNOWN");
		else printf("%d\n",dp[a][b]);
	}
}