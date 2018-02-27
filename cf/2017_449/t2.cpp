/*
	Writer:	Lizr2004
	School:	XTYF
	Time:	2017-12-02 22:22:38
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#define qing(arr) memset(arr,0,sizeof(arr))
#define full(arr) memset(arr,-1,sizeof(arr))
#define sinf(arr) memset(arr,0x3f,sizeof(arr))
#define ll long long
using namespace std;

int read(int& in) {
	in=0;char c=getchar(),ch=1;
	while(c<'0' || c>'9'){if(c=='-')ch=-ch; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=ch;
}
ll read(ll& in) {
	in=0;char c=getchar(),ch=1;
	while(c<'0' || c>'9'){if(c=='-')ch=-ch; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=ch;
}
int main(int argc, char const *argv[])
{
	freopen("in.txt","r",stdin);
	int n,mod;
	long long ans=0;
	read(n);read(mod);
	if(n<10)
	{
		for(int a=1;a<=n;a++)ans+=(11LL)*a;
		printf("%lld\n",ans%mod);
		return 0;
	}
	n-=9;ans=495LL;
	if(n<100)
	{
		for(int a=100,b=1;b<=n;a--,b++)
		{
			ans+=(a*10LL+b);
			while(ans>=mod)ans-=mod;
		}
		printf("%lld\n",ans%mod);
		return 0;
	}
	n-=99;ans=55935LL;
	if(n<1000)
	{
		for(int a=1000,b=1;b<=n;a--,b++)
		{
			ans+=(a*100LL+b);
			while(ans>=mod)ans-=mod;
		}
		printf("%lld\n",ans%mod);
		return 0;
	}
	n-=999;ans=605335LL;
	if(n<1000)
	{
		for(int a=10000,b=1;b<=n;a--,b++)
		{
			ans+=(a*1000LL+b);
			while(ans>=mod)ans-=mod;
		}
		printf("%lld\n",ans%mod);
		return 0;
	}
	// n-=9999;ans=
	return 0;
}
