/*
	Writer:	Lizr2004
	School:	XTYF
	Time:	2017-11-29 20:04:19
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
int n;
namespace segtree{
	#define N 200000*4
	int lson[N],rson[N];
	int sum[N],lazy[N];
	int root=1,cnt=1;
	inline int cal(int& ID)
	{
		if(ID==0)ID=++cnt;
		return ID;
	}
	inline void pushdown(int& ID,int l,int r)
	{
		const int mid=(l+r)>>1;
		lazy[lson[ID]]=lazy[ID];
		lazy[rson[ID]]=lazy[ID];
		sum[lson[ID]]=(mid-l+1)*(lazy[ID]-1);
		sum[rson[ID]]=(r-mid)*(lazy[ID]-1);
		lazy[ID]=0;
	}
	void update(int& ID,int l,int r,int L,int R,int x)
	{
		cal(ID);
		if(lazy[ID]==x)return;
		if(L<=l && r<=R)
		{
			lazy[ID]=x;
			sum[ID]=(r-l+1)*(lazy[ID]-1);
			return;
		}
		cal(rson[ID]);cal(lson[ID]);
		if(lazy[ID])pushdown(ID,l,r);
		const int mid=(l+r)>>1;
		if(l<=R && mid>=L) update(lson[ID],l,mid,L,R,x);
		if(r>=L && mid<=R) update(rson[ID],mid+1,r,L,R,x);
		sum[ID]=sum[lson[ID]]+sum[rson[ID]];
	}
	long long ask(int& ID,int l,int r,int L,int R)
	{
		cal(ID);
		if(lazy[ID])
		{
			int rl=max(L,l);
			int rr=min(R,r);
			return (rr-rl+1)*(lazy[ID]-1);
		}
		if(L<=l && r<=R)return sum[ID];
		int ans=0,mid=(l+r)>>1;
		if(l<=R && mid>=L)ans+=ask(lson[ID],l,mid,L,R);
		if(r>=L && mid<=R)ans+=ask(rson[ID],mid+1,r,L,R);
		return ans;
	}
	#undef N
}
namespace shupou{
	int head[131072],to[131072],pre[131072],fa[131072],tfa=1,tot;
	int shang[131072],xia[131072];
	int out()
	{
		return 0;
		for(int a=1;a<=n;a++)
			printf("%lld ",segtree::ask(segtree::root,1,n,a,a));
		putchar('\n');
	}
	void addedge(int a,int b)
	{
		pre[tfa]=head[a];
		head[a]=tfa;
		to[tfa]=b;
		fa[b]=a;
		tfa++;
	}
	int id[131072],sz[131072],sub[131072],dep[131072];
	char cmd[16];
	int dfs1(int now,int depth)
	{
		dep[now]=depth;
		sz[now]=1; int maxi=-1;
		for(int nex=head[now];nex;nex=pre[nex])
		{
			dfs1(to[nex],depth+1);
			sz[now]+=sz[to[nex]];
			if(maxi<sz[to[nex]])
			{
				maxi=sz[to[nex]];
				sub[now]=to[nex];
			}
		}
		return sz[now];
	}
	int dfs2(int now,int ding)
	{
		// printf("%d %d %d\n",now,ding,tot);
		shang[now]=ding;
		id[now]=++tot;
		if(sub[now])dfs2(sub[now],ding);
		else xia[now]=now;
		for(int nex=head[now];nex;nex=pre[nex])
			if(to[nex]!=sub[now])
				dfs2(to[nex],to[nex]);
	}
	void ins(int pac)
	{
		if(!pac)return;
		segtree::update(segtree::root,1,n,id[shang[pac]],id[pac],2);
		ins(fa[shang[pac]]);
	}
	int install(int pac)
	{
		int qian=segtree::ask(segtree::root,1,n,1,n);
		out();
		ins(pac);
		out();
		return segtree::ask(segtree::root,1,n,1,n)-qian;
	}
	int uninstall(int pac)
	{
		int qian=segtree::ask(segtree::root,1,n,1,n);
		out();
		segtree::update(segtree::root,1,n,id[pac],id[pac]+sz[pac]-1,1);
		out();
		return qian-segtree::ask(segtree::root,1,n,1,n);
	}
}
using namespace shupou;
int main(int argc, char const *argv[])
{
	// freopen("in.txt","r",stdin);
	read(n);
	// for(int a=0;a<n;a++)
	// 	segtree::update(segtree::root,1,n,a,a,0);
	for(int a=1;a<n;a++)
	{
		int fuck;
		read(fuck);
		addedge(fuck+1,a+1);
	}
	fa[1]=-1;
	if(dfs1(1,1)!=n)puts("FUCK");
	dfs2(1,1);
	// for(int a=1;a<=n;a++) printf("%d ",a); putchar('\n');
	// for(int a=1;a<=n;a++) printf("%d ",sub[a]); putchar('\n');
	// for(int a=1;a<=n;a++) printf("%d ",xia[a]); putchar('\n');
	// for(int a=1;a<=n;a++) printf("%d ",id[a]); putchar('\n');putchar('\n');
	int m; read(m);
	while(m--)
	{
		int opt;
		scanf("%s%d",cmd,&opt);
		if(cmd[0]=='i') printf("%d\n",install(opt+1));
		else printf("%d\n",uninstall(opt+1));
	}
	return 0;
}
