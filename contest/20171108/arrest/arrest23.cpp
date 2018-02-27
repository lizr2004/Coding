#include <iostream>
#include <stdio.h>
#include <string.h>

int n,m;
int vis[409600],tot;
int fa[409600];
int val[409600];
int find(int now) {
	if(now==fa[now])return now;
	return fa[now]=find(fa[now]);
}
int init(int maxi){ 
	for(int a=1;a<=maxi;a++) fa[a]=a,val[a]=1;
}
int read(int& in)
{
	in=0;char c=getchar();int cheng=1;
	while(c<'0' || c>'9'){if(c=='-')cheng=-1; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=cheng;
}
int main()
{
 	freopen("arrest.in","r",stdin);
	// freopen("arrest.out","w",stdout);
	int n,m,ans=0;
	read(n);read(m);
	init(n*3);
	for(int a=1;a<=m;a++)
	{
		int u,v;
		read(u);read(v);
		if(!vis[u]){tot++;vis[u]++;}
		if(!vis[v]){tot++;vis[v]++;}
		int ra=find(u);
		int rb=find(v);
		if(ra==rb)
		{
			// printf("%d\n",tot);
			// for(int b=1;b<=n;b++)
			// 	printf("%d %d %d\n",b,fa[b],val[b]);
			if(val[ra]&1){printf("-1 %d\n",a); return 0;}
		}
		else fa[ra]=rb,val[rb]+=val[ra]+1;
	}
	for(int a=1;a<=n;a++){if(fa[a]==a)ans+=val[a];}
	printf("1 %d\n",(ans>>1)+n-tot);
	return 0;
}
