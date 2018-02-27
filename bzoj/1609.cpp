#include <iostream>
#include <string.h>
#include <stdio.h>
int dp[30005],arr[30005];
int n;
int qiu1(int in[])
{
	memset(dp,0,sizeof(dp));
	dp[1]=in[0];
	int len =1;
	for(int i=1;i<n;i++)
	{
		int l=1;
		int r=len;
		while(l<=r)
		{
			int m = (l+r)/2;
			if(in[i]<dp[m]) r=m-1;
			else l=m+1;
		}
		dp[l] = in[i];
		if(l>len) len++;
	}
	return len;
}
int qiu2(int in[])
{
	memset(dp,0,sizeof(dp));
	dp[1]=in[0];
	int len =1;
	for(int i=1;i<n;i++)
	{
		int l=1;
		int r=len;
		while(l<=r)
		{
			int m = (l+r)/2;
			if(in[i]>dp[m]) r=m-1;
			else l=m+1;
		}
		dp[l] = in[i];
		if(l>len) len++;
	}
	return len;
}
int main()
{
	scanf("%d",&n);
	for(int a=0;a<n;a++)
		scanf("%d",arr+a);
	int ans=std::max(qiu1(arr),qiu2(arr));
	printf("%d\n",n-ans);
}
