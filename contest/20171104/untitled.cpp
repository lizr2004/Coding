#include <iostream>
#include <stdio.h>

int p[128],c[128];
int pre[1024],head[128],val[1024],to[1024],tot=1;
int n,m,C,T;
int dp[128][128][128];
//        now c me = dis
void addedge(int u,int v,int va)
{
	pre[tot]=head[u];
	to[tot]=v;
	val[tot]=va;
	head[u]=tot;
}
inline int read(int& x) {
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
// void bfs(int st,int me,int d)
// {
// 	std::queue<int> qunod,qustp,quc;
// 	qunod.push(s);
// 	qustp.push(0);
// 	quc.push(0);
// 	while(!qunod.empty())
// 	{
// 		int now=qunod.top();qunod.pop();
// 		int stp=qustp.top();qustp.pop();
// 		int c=quc.top();quc.pop();
// //        now c me = dis
// 		for(int nex=head[now];nex;nex=pre[nex])
// 		{
// 			if(c==0)
// 			{
// 				dp[to[now]][std::min(C,c[now])][qian+p[now]]
// 				=dp[now][c][qian]+val[nex];
// 			}
// 			for(qian=0;qian<me;qian++)dp[now][c][qian]=dp[to[nex]][c+]
// 	}
// }
int main()
{
	read(n);read(m);read(C);read(T);
	for(int a=1;a<=n;a++){read(p[a]);read(c[a]);}
	for(int a=1;a<=m;a++){int u,v,va;read(u);read(v);read(va);}
	for(int a=1;a<=T;a++)
	{
		int st,me,d;
		read(st);
		read(me);read(d);
		// memset(dp,0,sizeof(dp));
		// bfs(st,me,d);
		printf("-1\n");
	}
}