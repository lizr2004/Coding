#include <iostream>
#include <stdio.h>
#include <string.h>

int arr[32][2];
int ljt[32];
int ans=0x3f3f3f3f,n,m;
void dfs(int depth)
{
	if(depth==n+1)
	{
		int sum=0;
		for(int a=1;a<=m;a++)
		{
			// printf("%d ",ljt[a]);
			if(ljt[a]&1)
				sum++;
		}
		// printf("%d\n",sum );
		ans=std::min(ans,sum);
		return;
	}
	ljt[arr[depth][0]]++;
	dfs(depth+1);
	ljt[arr[depth][0]]--;
	ljt[arr[depth][1]]++;
	dfs(depth+1);
	ljt[arr[depth][1]]--;
}

int main()
{
	freopen("rubbish.in","r",stdin);
	freopen("rubbish.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>10000){puts("0");return 0;}
	for(int a=1;a<=n;a++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		arr[a][0]=x;
		arr[a][1]=y;
	}
	dfs(1);
	printf("%d\n",ans);
}