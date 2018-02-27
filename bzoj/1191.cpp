#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int ma[100001][100001],fa[100001];
int n,m;
bool y[100001];
bool find(int x)
{
	for(int i=0;i<n;i++)
	{
		if(!y[i]&&ma[x][i])
		{
			y[i]=1;
			if(!fa[i]||find(fa[i]))
			{
				fa[i]=x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		ma[i][x]=ma[i][y]=1;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		memset(y,0,sizeof(y));
		if(find(i))ans++;
		else break;
	}
	printf("%d\n",ans);
	return 0;
}