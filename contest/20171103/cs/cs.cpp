#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int n,m,sx,sy,ex,ey,ans=0x3f3f3f3f,realdep=0x3f3f3f3f;
char arr[512][512];
bool vis[512][512];
const int ru1[]={-1,-1,-1,0,0,1,1,1};
const int ru2[]={-1,0,1,-1,1,-1,0,1};
inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
void dfs(int x,int y,int ti,int dep)
{
	if(x==ex && y==ey)
	{
		if(ans>ti) ans=ti; realdep=dep;
		if(ans==ti) realdep=std::min(dep,realdep);
		return;
	}  
	for(int nex=0;nex<8;nex++)
	{
		int nexx=x+ru1[nex], nexy=y+ru2[nex];
		if(nexx>n || nexx<1 || nexy>m || nexy<1)continue;
		if(arr[nexx][nexy]=='0')continue;
		if(vis[nexx][nexy])continue;
		vis[nexx][nexy]=1;
		if(arr[nexx][nexy]==arr[x][y])dfs(nexx,nexy,ti,dep+1);
		else dfs(nexx,nexy,ti+1,dep+1);
		vis[nexx][nexy]=0;
	}
}
int main()
{
	freopen("cs.in","r",stdin);
	// freopen("cs.out","w",stdout);
	read(n);read(m);read(sx);read(sy);read(ex);read(ey);
	for(int a=1;a<=n;a++) scanf("%s",arr[a]+1);
	dfs(sx,sy,0,1);
	printf("%d %d\n",realdep,ans);
}
