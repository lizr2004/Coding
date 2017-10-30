#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int father[101],v[101],flag,t;
int find(int x)
{
	if(father[x]==x)return x;
	t=find(father[x]);
	v[x]+=v[father[x]];
	father[x]=t;
	return father[x];
}

void work(int x,int y,int w)
{
	int p=find(x),q=find(y);
	if(p!=q)
	{
		father[p]=q;
		v[p]=v[y]-v[x]-w;
	}
	else if(v[y]-v[x]!=w)flag=1;
}

int main()
{
	int w,n,m,x,y,z;
	scanf("%d",&w);
	while(w--)
	{
		memset(v,0,sizeof(v));
		flag=0;
		scanf("%d%d",&n,&m);
		for(int i=0;i<=n;i++)
			father[i]=i;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			work(x-1,y,z);
		}
		if(flag)puts("false");
		else puts("true");
	}
	return 0;
}
