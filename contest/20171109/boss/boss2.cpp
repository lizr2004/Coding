#include <iostream>
#include <stdio.h>
#include <string.h>
const int mod=1000000007;
int main()
{
	freopen("boss.in","r",stdin);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int now;
		scanf("%d",&now);
		now%=mod;
		int a=now/6*6;
		int ans=((((2*a+1)%mod)*((a+1)%mod)%mod)*((a/6)%mod))%mod;
		ans+=((1+a)*a)>>1;
		ans%=mod;
		for(int b=a+1;b<=now;b++)
		{
			ans+=(((((b+1)%mod)*(b%mod))%mod)>>1);
			ans%=mod;
		}
		printf("%d\n",ans);
	}
}