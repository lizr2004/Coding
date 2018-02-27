#include <iostream>
#include <string.h>
using namespace std;

int dp[1000][10000];
//     time health
int main()
{
	int n,m,t;
	int time,h,w;
	cin>>n>>m>>t;
	m--;
	while(n--)
	{
		cin>>time>>time>>h>>w;
		for(int a=t;a>=time;a--)
			for(int b=m;b>=h;b--)
				dp[a][b]=max(dp[a][b],dp[a-time][b-h]+w);
	}
	cout<<dp[t][m]<<endl;
}