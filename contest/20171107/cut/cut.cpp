#include <iostream>
#include <stdio.h>
#include <string.h>
int ans;
int main()
{
	freopen("cut.in","r",stdin);
	// freopen("cut.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int a=1;a<=n;a++)
		for(int b=1;b<=m;b++)
		{
			for(int x=1;x<=n;x++)
				for(int y=1;y<=m;y++)
				{
					printf("%d %d %d %d\n",a,b,x,y);
					int tot=1,tx=x,ty=y;
					while(tot<=k && x<=n && y<=m)
					{
						tx+=a;
						ty+=y;
						tot++;
					}
					if(tot==k)ans++;
				}
		}
	printf("%d\n",ans);
}