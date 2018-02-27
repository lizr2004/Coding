#include <iostream>
#include <string.h>
using namespace std;

int dp[2005][2005];
char s[2005],t[2005];
int k;
inline int abs(int a) {if(a>=0)return a; else return -a; }
int main()
{
	cin>>s+1>>t+1;
	cin>>k;
	int len1=strlen(s+1),len2=strlen(t+1);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<=len1;i++)
		for(int j=0;j<=len2;j++)
			if(dp[i][j]!=0x3f3f3f3f)
				{
					dp[i+1][j]=min(dp[i+1][j],dp[i][j]+k);//space
					dp[i][j+1]=min(dp[i][j+1],dp[i][j]+k);//space
					dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+abs(s[i+1]-t[j+1]));//letter <-> letter
				}
	cout<<dp[len1][len2]<<endl;
}
