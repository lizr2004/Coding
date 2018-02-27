#include <stdio.h>
#include <iostream>

int con[128][128];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		con[u][v]=-1;
		con[v][u]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
			{
				if(con[i][j]==0)
				{
					if(con[i][k]==1 && con[k][j]==1)
						con[i][j]=1,con[j][i]=-1;
					else if(con[i][k]==-1 && con[k][j]==-1)
						con[i][j]=-1,con[j][i]=1;
				}
				else
					break;
			}
	int out=0;
	for(int i=1;i<=n;i++)
	{
		int tmp=0;
		for(int j=1;j<=n;j++)
			if(i!=j && con[i][j]==0)
				tmp++;
		if(tmp==0)
			out++;
	}
	printf("%d\n",out);
}