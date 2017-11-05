#include <iostream>
#include <stdio.h>
#include <string.h>
int n;
int yes[4][4];
bool first[4];
int arr[10240][4];
char brr[10240];
char ans[10240];
char getrealchar()
{
	char c=getchar();
	while(c>'D' || c<'A')c=getchar();
	return c-'A';
}
bool dfs(int dep,int now,int a,int b,int c,int d)
{
	if(n<now)return false;
	if(dep>=5){if(now==n)return true;return false;}
	for(int nex=0;nex<4;nex++)
		if(yes[dep][now]!=-1)
			if(dfs(dep+1,a+bool(nex==0),b+bool(nex==1),c+bool(nex==2),d+bool(nex==3),now+yes[dep][now]))
			{
				ans[dep]=yes[dep][now];
				return true;
			}
	return  false;
}
int main()
{
	freopen("niubi.in","r",stdin);
	// freopen("niubi.out","w",stdout);
	scanf("%d",&n);
	for(int a=1;a<=n;a++)

	{
		brr[a]=getrealchar();
		scanf("%d%d%d%d",&arr[a][0],&arr[a][1],&arr[a][2],&arr[a][3]);
		if(!first[brr[a]])
		{
			first[brr[a]]=true;
			yes[brr[a]][0]=arr[a][0];
			yes[brr[a]][1]=arr[a][1];
			yes[brr[a]][2]=arr[a][2];
			yes[brr[a]][3]=arr[a][3];
		}
		else for(int a=0;a<4;a++)
		{
			if(yes[brr[a]][a]==-1)break;
			bool canit=false;
			for(int b=0;b<4;b++) if(yes[brr[a]][a]==arr[a][b])canit=1;
			if(!canit)yes[brr[a]][a]=-1;
		}
	}
	dfs(0,0,0,0,0,0);
	// if(!ans[0])
	// 	for(int a=1;a<=4;a++)
	// 		for(int b=1;b<=4;b++)
	// 			if(yes[a][b]!=-1){ans[a]=yes[a][b];break;}
	// for(int a=1;a<=4;a++)printf("%d ",ans[a]);
	for(int a=1;a<=n;a++)
		for(int b=0;b<4;b++)
			if(ans[brr[a]]==arr[a][b])
			{
				// printf("%d %d ",a,b);
				putchar('A'+b);
				break;
			}
	printf("\n");
}

