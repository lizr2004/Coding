#include <iostream>
#include <stdio.h>
using namespace std;

int  en[100000];
int  ma[100000][27];
int  n,q;
char ch[21];
int  tot=2;
void dfs1(int ind,char c[],int now)
{
//	printf("FUCKU");
	if(c[0]==0)
	{
		en[now]=ind;
		return;
	}
	else if(ma[now][c[0]])
		dfs1(ind,c+1,ma[now][c[0]]);
	else
	{
		ma[now][c[0]]=tot++;
		dfs1(ind,c+1,ma[now][c[0]]);
	}
}
int dfs0(int now)
{
	int ans=0;
	for(int a=1;a<=26;a++)
		if(ma[now][a])
			ans=max(ans,dfs0(ma[now][a]));
	if(en[now])ans++;
	return ans;
}
int main()
{
	scanf("%d",&n);
	int b;
	const char hahaha='a'-1;
	for(int a=1;a<=n;a++)
	{
		scanf("%s",ch);
		b=-1;
		while(1)
		{
			b++;
			if(!ch[b])break;
			ch[b]-=hahaha;
		}
		dfs1(a,ch,1);
	}
	printf("%d",dfs0(1));
	return 0;
}
