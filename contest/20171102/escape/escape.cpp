#include <iostream>
#include <stdio.h>
inline int abs(int a){return a<0?-a:a;}
inline int getdis(int a,int b,int c,int d) {return abs(a-b)+abs(c-d);}
int sx,sy,n,m,N,ex,ey;
int xs[1024],ys[1024];
inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
int main()
{
	freopen("escape.in","r",stdin);
	freopen("escape.out","w",stdout);
	int ans=-1;
	read(N);read(n);read(m);read(sx);read(sy);read(ex);read(ey);
	for(int a=1;a<N;a++)
	{
		read(xs[a]);
		read(ys[a]);
		ans=std::max(ans,getdis(sx,sy,xs[a],ys[a]));
		ans=std::max(ans,getdis(ex,ey,xs[a],ys[a]));
	}
	printf("%d %d\n",ans,getdis(sx,sy,ex,ey));
}