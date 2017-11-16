#include <iostream>
#include <stdio.h>
#include <string.h>
#define val(a) (valf[a]+valb[a])
int fa[204800]; int valf[204800]; int valb[204800]; bool vis[204800];
int find(int now) {
	if(fa[now]==now)return now;
	return fa[now]=find(fa[now]);
}
int init(int max) {
	for(int a=1;a<=max;a++)
		fa[a]=a,valf[a]=valb[a]=1;
}
int main() {
	freopen("arrest.in","r",stdin);
	// freopen("arrest.out","w",stdout);
	int n,m;
	read(n);read(m);
	init(m<<1);
	for(int a=1;a<=m;a++)
	{
		int u,v;
		read(u);read(v);
		if(unio(u,v+n) && (val(find(u))&1) ) {printf("-1 %d\n",a); return 0;}
		if(unio(v,u+n) && (val(find(v))&1) ) {printf("-1 %d\n",a); return 0;}
	}
}