#include <iostream>
#include <stdio.h>
#include <string.h>
#define aqx

int arr[3];
char can[16];
int s,n,ans;
void dfs2(int now,int sum)
{
	if(sum==0 && now==n){ans++;return;}
	if(arr[0]==arr[1] && now==n){ans++;return;}
	if(now==n)return;
	for(int a=0;a<s;a++)
	{
		arr[now&1]++;
		dfs2(now+1,sum-can[a]);
		arr[now&1]--;
	}
}
void dfs1(int now,int sum)
{
	if(now==n){dfs2(0,sum);return;}
	for(int a=0;a<s;a++)
	{
		arr[(now+n)&1]++;
		dfs1(now+1,sum+can[a]);
		arr[(now+n)&1]--;
	}
}
int main()
{
	freopen("num.in","r",stdin);
	// freopen("num.out","w",stdout);
	scanf("%d%s",&n,can);
	s=strlen(can);
	for(int a=0;a<s;a++)
		can[a]-='0';
	dfs1(0,0);
	printf("%d\n",ans);
}
