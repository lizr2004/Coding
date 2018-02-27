#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
const int ra[]={0,0,-1,1},rb[]={1,-1,0,0};
int dm[315][315];
int vis[315][315];
struct Nod{int x,y,t;};
int n;
int bfs()
{
	std::queue<Nod> qu;
	qu.push((Nod){0,0,0});
	while(!qu.empty())
	{
		Nod now=qu.front();
		qu.pop();
		if(dm[now.x][now.y]==0x3f3f3f3f)return now.t;
		if(now.t<=dm[now.x][now.y])continue;
		if(vis[now.x][now.y]<=now.t)continue;
		for(int a=0;a<4;a++)
		{
			int nexx=now.x+ra[a],
				nexy=now.y+rb[a],
				next=now.t+1;
			if(nexx<)
			qu.push((Nod){now.x+ra[a],now.y+rb[a],now.t+1});
			vis[now.x+ra[a]][now.y+rb[a]]=now.t+1;
		}
	}
	return -1;
}
int main()
{
	memset(dm,0x3f,sizeof(dm));
	memset(vis,0x3f,sizeof(vis));
	scanf("%d",&n);
	while(n--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		dm[a][b]=std::min(dm[a][b],c);
		for(int i=0;i<4;i++)
		{
			int nexa=a+ra[i],nexb=b+rb[i];
			dm[nexa][nexb]=std::min(dm[nexa][nexb],c);
		}
	}
	printf("%d",bfs());
	return 0;
}