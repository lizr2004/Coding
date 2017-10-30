#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>

int v[50005];
int n,m,d,l,ans;
int main()
{
	scanf("%d%d%d%d",&n,&m,&d,&l);
	for(int i=1;i<=n;i++)
		scanf("%d",v+i);
	std::sort(v+1,v+n+1);
	for(int i=1;i<=n;i++)
	{
		int t=ans/m;
		if(v[i]-t*d>=l)ans++;
	}
	printf("%d\n",ans);
	return 0;
}