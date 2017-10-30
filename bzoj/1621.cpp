#include <iostream>
#include <stdio.h>
int n,k;
int dfs(int now)
{
	// printf("%d\n",now);
	if(now<=k || ((now-k)&1))return 1;
	int ans=0;
	ans+=dfs((now-k)>>1);
	ans+=dfs((now+k)>>1);
	return ans;
}

int main()
{
	scanf("%d%d",&n,&k);
	printf("%d",dfs(n));
}