#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
#define mp(a,b) make_pair(a,b)
#define pib pair<int,bool>
using namespace std;
int n,m;
bool black[5120][2];
int w[5120],s[5120];
int to[38600],pre[38600],head[5120],value[38600],tot=1;
bool in[5120];int dis[5120][2];
void addedge(int u,int v,int w)
{
	pre[tot]=head[u];
	value[tot]=w;
	to[tot]=v;
	head[u]=tot;
}
int spfa(int qi,int zhong)
{
	queue<pair<int,bool> > qu;
	while(!qu.empty())qu.pop();
	qu.push(mp(qu,0));
	memset(dis,0x3f,sizeof(dis));
	dis[qi]=0;in[qi]=1;
	int time=0;
	while(!qu.empty())
	{
		pib nowp=qu.top();
		qu.pop(),in[now.first]=0;
		for(int fake_nex=head[now];fake_nex;fake_nex=pre[fake_nex])
		{
			int nex=to[fake_nex];
			int val=value[now.first];
			if(black[nex][nowp.second]!=black[now][nowp.second])
			if(dis[now]+val)
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);int tmp;
	for(int a=1;a<=n;a++){scanf("%d",&tmp);black[a][1]= !(black[a][0]=tmp);}
	for(int a=1;a<=n;a++) scanf("%d",w+a);
	for(int a=1;a<=n;a++) scanf("%d",s+a);
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);addedge(v,u,w);
	}
	printf("%d\n",spfa(1,n));
}
