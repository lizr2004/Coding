#include <iostream>
#include <stdio.h>
int dp[102400];
inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}

int main()
{
	freopen("password.in","r",stdin);
	freopen("password.out","w",stdout);
	int n,m;read(n);read(m);dp[51200]=1;
	while(n--) 
	{
		int now;read(now);
		if(now>=0)for(int a=102400;a>=now;a--)dp[a]+=dp[a-now];
		else for(int a=102400+now;a>=0;a--)dp[a]+=dp[a-now];
	}
	printf("%d\n",dp[51200+m]);
}
