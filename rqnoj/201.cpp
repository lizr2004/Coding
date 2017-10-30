#include <iostream>
#include <string.h>
using namespace std;

int arr[4005];
int dp[2005],ans=0x3f3f;
int n;

// short qiu(int in[])
// {
// 	short t=-1;
// 	for(short a=0;a<n;a++)
// 	{
// 		dp[a]=1;
// 		for(short b=0;b<a;b++)
// 			if(in[a]>=in[b] && dp[a]<(dp[b]+1))
// 				dp[a]=dp[b]+1;
// 		t=max(t,dp[a]);
// 	}
// 	return t;
// }
int qiu(int in[])
{
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

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(short a=0;a<n;a++)
	{
		cin>>arr[a];
		arr[a+n]=arr[a];
	}
	for(short a=0;a<n;a++)
	{
		memset(dp,0,sizeof(dp));
		ans=min(ans,qiu(arr+a));
	}
	cout<<ans<<endl;
}

