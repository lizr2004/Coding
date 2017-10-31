#include <iostream>
#include <stdio.h>
#include <math.h>
int pre[5120];
bool ed[5120][5120];
inline int abs(int in){return in>=0?in:-in;}
inline bool can(int a,int b,int r){return (r*r-a*a-b*b)>=0;}
int main()
{
	freopen("destroy.in","r",stdin);
	freopen("destroy.out","w",stdout);
	int n,m,ans;
	scanf("%d%d",&n,&m);ans=0;
	if(n>500){puts("0");return 0;}
	// printf("%d\n",n);
	while(m--)
	{
		int  x,y,r;
		scanf("%d%d%d",&x,&y,&r);
		for(int a=-r;a<=r;a++)
			for(int b=-r;b<=r;b++)
				if(can(abs(a),abs(b),r))
					ed[x-a][y-b]=1;
	}
	for(int a=1;a<=n;a++)
		for(int b=1;b<=n;b++)
			if(ed[a][b])
				ans++;
	printf("%d\n",n*n-ans);
}