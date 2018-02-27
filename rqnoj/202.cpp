#include <iostream>
#include <string.h>
using namespace std;

int dp[205][205];
int N,O,n;
int x,y,z;
int minW=0x3f3f3f3f;
int main()
{
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	cin>>O>>N>>n;
	while(n--)
	{
		cin>>x>>y>>z;
		for(int i=O;i>=0;i--)
			for(int j=N;j>=0;j--)
			{	
				int a=min(i+x,O),b=min(j+y,N);
				dp[a][b]=min(dp[a][b],dp[i][j]+z);
			}
	}
	cout<<dp[O][N]<<endl;
}