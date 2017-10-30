#include <iostream>
#include <stdio.h>

int dp[13000];

int main(int argc, char const *argv[])
{
	int N,M,maxv=0,maxw=0,maxi=-1;
	scanf("%d%d",&N,&M);
	while(N--)
	{
		int nowv,noww;
		scanf("%d%d",&nowv,&noww);
		maxv=std::min(maxv+nowv,M);
		for(int i=maxv-nowv;i>=0;i--)
			maxi=std::max(maxi,
				dp[i+nowv]=std::max(dp[i]+noww,dp[i+nowv])
			);
	}
	printf("%d\n",maxi);
}