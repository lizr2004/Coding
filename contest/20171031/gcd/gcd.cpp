#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
int ans=0,n,k;
int vis[512000];
int arr[512000];
int maxn=-1;
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int a=1;a<=n;a++)
	{
		scanf("%d",arr+a);
		vis[arr[a]]++;
		maxn=std::max(maxn,arr[a]);
	}
	for(int now=maxn;now>0;now--)
	{
		int duoshaoge=0;
		for(int a=now;a<=maxn;a+=now)
			duoshaoge+=vis[a];
		if(duoshaoge>=k)
		{
			printf("%d \n",k*now);
			return 0;
		}
	}
	printf("%d\n",k);
}