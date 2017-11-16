#include <iostream>
#include <stdio.h>
#include <string.h>

const int mod=1000000007;
const int fuck=166666668;
int main() {
	// freopen("boss.in","r",stdin);
	// freopen("boss.out","w",stdout);
	int n; scanf("%d",&n);
	while(n--){
	// while(1){
		long long now,ans=0LL;
		scanf("%lld",&now);
		ans+=((((1+now)%mod)*(now%mod))%mod)*500000004;ans%=mod;
		ans+=((((2*now+1)%mod)*(((now+1))%mod)%mod)*((now)%mod)%mod)*166666668;
		ans%=mod;
		printf("%lld\n",(((ans%mod))*500000004)%mod);
	}
}