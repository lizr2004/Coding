#include <iostream>
#include <stdio.h>

int arr[10240];
int brr[10240];
short dp[10240][10240];
inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
int main()
{
	freopen("formation.in","r",stdin);
	freopen("formation.out","w",stdout);
	int n;
	read(n);
	for(int a=1;a<=n;a++)read(arr[a]);
	for(int a=1;a<=n;a++)read(brr[a]);
	for(int a=1;a<=n;a++)
		for(int b=1;b<=n;b++)
		{
			if(arr[a]==brr[b])
				dp[a][b]=dp[a-1][b-1]+1;
			else
				dp[a][b]=std::max(dp[a-1][b],dp[a][b-1]);
		}
	printf("%d\n",dp[n][n]);
}