#include <iostream>
#include <stdio.h>
#include <string.h>

int n,m;
int vis[102400],tot;
	int fa[204800];
	int find(int now) {
		if(now==fa[now])return now;
		return fa[now]=find(fa[now]);
	}
	int init(int maxi){
		for(int a=1;a<=maxi;a++) fa[a]=a;
	}
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
	freopen("arrest.out","w",stdout);
	int n,m,ans=0;
	read(n);read(m);
	ufs::init(n*2+32);
	for(int a=1;a<=m;a++)
	{
		int u,v;
		read(u);read(v);
		if(!vis[u]){tot++;vis[u]++;}
		if(!vis[v]){tot++;vis[v]++;}
		int ra=ufs::find(u);
		int rb=ufs::find(v);
		if(ra==rb){printf("-1 %d\n",a);return 0;}
		else{
			ufs::fa[ufs::find(ra+n)]=rb;
			ufs::fa[ufs::find(rb+n)]=ra;
			ans++;
		}
	}
	printf("1 %d\n",(ans>>1)+n-tot);
	return 0;
}
