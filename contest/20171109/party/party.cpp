#include <iostream>
#include <map>
#include <string.h>
#include <stdio.h>

int mins=0x3f3f3f3f;
int tot=1,root;

int to[40960],pre[40960],head[40960],fa[40960];
int anc[40960][20],dep[40960];
int cps[102400][2];
void addedge(int a,int b)
{
	//a->b
	fa[b]=a;
	pre[tot]=head[a];
	to[tot]=b;
	head[a]=tot;
	tot++;
}

void dfs(int now,int depth)
{
	if(dep[now])return;
	dep[now]=depth;
	anc[now][0]=fa[now];
	for(int a=1;a<18;a++)
		anc[now][a]=anc[anc[now][a-1]][a-1];
	for(int nex=head[now];nex;nex=pre[nex])
		dfs(to[nex],depth+1);
}

int lca(int a,int b)
{
	// puts("--------------");
	if(dep[a]>dep[b]){std::swap(a,b);}
	//dep[b]  >  dep[a]
	int cha=dep[b]-dep[a],bei=0;
	// printf("fuck %d\n",cha);
	while(cha)
	{
		// printf("%d  fuck  %d\n",a,b);
		if(cha&1)b=anc[b][bei];
		bei++;
		cha>>=1;
	}
	if(a==b)return a;
	for(int bei=18;bei>=0;bei--)
		if(anc[a][bei]!=anc[b][bei])
		{
			a=anc[a][bei];
			b=anc[b][bei];
		}
	return anc[a][0];
}

int main()
{
	freopen("party.in","r",stdin);
	freopen("party.out","w",stdout);
	int n,m; scanf("%d %d",&n,&m);
	for(int gg=1;gg<n;gg++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		addedge(b,a);
		addedge(a,b);
	}
	for(int a=1;a<=m;a++)
		scanf("%d%d",&cps[a][0],&cps[a][1]);
	for(int a=1;a<=n;a++)
	{
		memset(anc,0,sizeof(anc));
		memset(dep,0,sizeof(dep));
		dfs(a,1);int ans=0;
		for(int b=1;b<=m;b++)
			ans+=lca(cps[b][0],cps[b][1]);
		mins=std::min(ans,mins);
	}
	printf("%d\n",mins);
	return 0;
}
