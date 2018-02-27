#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
int ma[1024][1024];
int vis[1024][1024];
int ru1[10]={1,-1,0,0,1,1,-1,-1};
int ru2[10]={0,0,-1,1,-1,1,-1,1};
int n,m,ans=0,tot=0;
struct NOD{int x,y,h;};
NOD nod[512000];
bool cmp(NOD a,NOD b) {return a.h>b.h; }
void dfs(int a,int b,int flag)
{
	if(a==0 || b==0 || a>n || b>m)return;
	vis[a][b]=flag;
	for(int c=0;c<8;c++)
	{
		const int nexa=a+ru1[c],nexb=b+ru2[c];
		if(nexa>0 && nexb>0 && nexa<=n && nexb<=m && (!vis[nexa][nexb]) && ma[a][b]>=ma[nexa][nexb])
			dfs(nexa,nexb,flag);
	}
}

int main()
{
	memset(ma,-1,sizeof(ma));
	scanf("%d%d",&n,&m);
	for(int a=1;a<=n;a++)
		for(int b=1;b<=m;b++)
		{
			scanf("%d",&ma[a][b]);
			nod[tot++]=(NOD){a,b,ma[a][b]};
		}
	std::sort(nod,nod+tot,cmp);
	int tot2=1;
	for(int a=0;a<tot;a++)
	{
		if(!vis[nod[a].x][nod[a].y])
			dfs(nod[a].x,nod[a].y,tot2++),ans++;
	}
	printf("%d\n",ans);
}