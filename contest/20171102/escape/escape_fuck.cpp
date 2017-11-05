#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
int sx,sy,n,m,N,ex,ey;
int xs[1024],ys[1024];
int vis[1024][1024];
struct nod {int dis,x,y,step;};
inline int abs(int a){return a<0?-a:a;}
inline int getdis(int a,int b,int c,int d) {return abs(a-b)+abs(c-d);}
inline int bfs()
{
	int mindis=0x3f3f3f3f;
	queue<nod> qu;
	nod start;
	start.x=sx,start.y=sy,start.step=0;
	qu.push(start);
	while(!qu.empty()){
		nod top=qu.front();
		qu.pop();
		if(qu.x!=n){}
	}
}
int main()
{
	read(N);read(n);read(m);read(sx);read(sy);read(ex);read(ey);
	for(int a=1;a<N;a++){read(xs[a]); read(ys[a]); }
	bfs();
	printf("%d %d\n",ans,dis);
}