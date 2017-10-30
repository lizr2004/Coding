#include <iostream>
using namespace std;
long long num[50][50];
long long dp[50][50];
char s[50];
int N,K;
int main()
{
    cin>>N>>K;
	cin>>s;
	for(int a=0;a<N;a++)
	{
		num[a][a]=s[a]-'0';
		for(int b=a+1;b<N;b++)
			num[a][b]=num[a][b-1]*10+(s[b]-'0');
	}
	for(int a=0;a<N;a++)
		dp[a][0]=num[0][a];
	for(int a=0;a<N;a++)
		for(int b=0; b<=K && b<a+1 ;b++)
			for(int m=b;m<=a;m++)
				dp[a][b]=max(dp[a][b],dp[m-1][b-1]*num[m][a]);
	cout<<dp[N-1][K]<<endl;
	return 0;
}