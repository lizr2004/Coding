#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
int pre[5120];
char ed[5120][5120];
inline int abs(int in){return in>0?in:-in;}
inline bool can(int a,int b,int r){return (r*r-a*a-b*b)>=0;}
int main()
{
	freopen("destroy.in","r",stdin);
	// freopen("destroy.out","w",stdout);
	int n,m,ans;
	scanf("%d%d",&n,&m);ans=0;
	for(int a=1;a<=n;a++)
		for(int b=1;b<=n;b++)
			ed[a][b]=b;
	while(m--)
	{
		int  x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		memset(ed[x],1,sizeof(char)*(r*2-1));
		for(int a=1;a<=r;a++)
		{
			int  dis=std::max(1, (int)sqrt(r*r-a*a)+x-r );
			memset(ed[x-a],1,sizeof(int)*(dis*2-1));
			memset(ed[a+x],1,sizeof(int)*(dis*2-1));
		}
	}
	for(int a=1;a<=n;a++)for(int b=1;b<=n;b++)if(ed[a][b])ans++;
	// for(int a=1;a<=n;a++) ans+=ed[a][n];
	// for(int a=1;a<=n;a++){for(int b=1;b<=n;b++)printf("%d ",ed[a][b]);puts("");}
	printf("%d\n",n*n-ans);
}