#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define LD long double
using namespace std;
unsigned long long a,b,n;
LD ksm(LD di,unsigned long long mi)
{
	LD ans=1;
	while(mi)
	{
		if(mi&1) ans=(ans*di);
		while(ans>100000)ans-=100000;
		mi>>=1; di=di*di;
		while(di>100000)di-=100000;
	}
	return ans;
}
int main()
{
	freopen("bignum.in","r",stdin);
	freopen("bignum.out","w",stdout);
	scanf("%lld%lld%lld",&a,&b,&n);
	printf("%03d\n",(int)(ksm(a+sqrt(b),n))%1000);
}