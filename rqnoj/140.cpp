#include <stdio.h>
int a[1001];
int dp[10001];
int main()
{
	int t,n,vs,i,j;
	scanf("%d%d%d",&t,&n,&vs);
	while(n--)
	{
		for(i=1;i<=t;i++)
			scanf("%d",&a[i]);
		for(i=t;i>vs;i--)
			for(j=1;i-vs-j>=0;j++)
				if( dp[i]<dp[i-vs-j]+a[j] )
					dp[i]=dp[i-vs-j]+a[j];
	}
	printf("%d\n",dp[t]);
	return 0;
}