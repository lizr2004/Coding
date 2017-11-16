#include <iostream>
#include <stdio.h>
#include <string.h>
const int mod=1000000007;
const int biao=1000000;
int main()
#define int long long
{
	freopen("boss.in","r",stdin);
	// freopen("boss.arr","w",stdout);
	int n;
	scanf("%lld",&n);
	while(n--)
	{
		int now,ans=0;
		scanf("%lld",&now);
		for(int a=1;a<=now;a++){
			ans+=((a%mod+1)*(a%mod))>>1;
			ans%=mod;
		}
		printf("%lld\n",ans);
	}
}