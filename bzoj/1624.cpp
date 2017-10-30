#include<iostream>
#include<stdio.h>
int n,m,a[10001],d[101][101],ans;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&d[i][j]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				d[i][j]=std::min(d[i][j],d[i][k]+d[k][j]);
	for(int i=1;i<m;i++)
		ans+=d[a[i+1]][a[i]];
	ans+=d[1][a[1]];ans+=d[a[m]][n];
	printf("%d",ans);
	return 0;
}
