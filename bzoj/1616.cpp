#include <iostream>
#include <stdio.h>
#include <string.h>
int n,m,t,r1,c1,r2,c2;
int dp[16][128][128];
bool ma[128][128];
int ru1[]={1,-1,0,0};
int ru2[]={0,0,-1,1};
inline bool chk(int a,int b)
{
	if(a<=0 || a>n || b<=0 || b>m)return 1;
	if(ma[a][b])return 1;
	return 0;
}
int main()
{
	scanf("%d %d %d",&n,&m,&t);
	for(int a=1;a<=n;a++)
		for(int b=1;b<=m;b++)
		{
			char now;
			do{now=getchar();}while(now!='*'&&now!='.');
			if(now=='*')
				ma[a][b]=1;
			// puts("It was fucked!");
		}
	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
	dp[0][r1][c1]=1;
	for(int nt=1;nt<=t;nt++)
	{
		for(int a=1;a<=n;a++)
			for(int b=1;b<=m;b++)
			{
				if(chk(a,b))continue;
				for(int fx=0;fx<4;fx++)
				{
					int nexa=a+ru1[fx],
							nexb=b+ru2[fx];
					if(chk(nexa,nexb))continue;
					dp[nt][nexa][nexb]+=dp[nt-1][a][b];
				}
			}
	}
	// for(int nt=1;nt<=t;nt++)
	// {
	// 	for(int a=1;a<=n;a++)
	// 	{
	// 		for(int b=1;b<=m;b++)
	// 			printf("% 10d ",dp[nt][a][b]);
	// 		putchar('\n');
	// 	}
	// 	printf("\n\n");
	// }
	printf("%d",dp[t][r2][c2]);
}