#include <iostream>
#include <map>
#include <stdio.h>

int tot=1,root;

int to[40960],pre[40960],head[40960],fa[40960];
int anc[40960][20],dep[40960];

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
	int flag=0;
	if(dep[a]>dep[b]){std::swap(a,b);flag=-1;}
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
	if(a==b)
		return -flag+1;
	return 0;
}

int main()
{
	// freopen("tree.in","r",stdin);
	// freopen("tree.out","w",stdout);
	int n; scanf("%d",&n);
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(b==-1)root=a,fa[a]=-1;
		else addedge(b,a);
	}
	dfs(root,1);
	scanf("%d",&n);
	while(n--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}
