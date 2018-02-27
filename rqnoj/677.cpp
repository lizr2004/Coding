#include <iostream>
#include <stdio.h>
using namespace std;
int dp[1086][1086];
//	   jing  13
int A,n,B;
int ans=-1;
int jing,mei,b13;
char* tran[] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};  
char* tran2[] = {"ling","yi","liang","san","si","wu","liu","qi","ba","jiu"};  
void translate(int ans)
{
	int weishu;
	if (ans > 999)
		weishu = 4;
	else if (ans > 99)
		weishu = 3;
	else if (ans > 9)
		weishu = 2;
	else if (ans > 0)
		weishu = 1;
	else weishu = 0;
	
	switch(weishu)
	{
		case 0:
			printf("ling");
			break;
		case 1:
			printf("%s",tran[ans]);
			break;
		case 2:
			if (ans>19)
				printf("%s ",tran[ans/10]);
			printf("shi");
			if (ans%10)
				printf(" %s",tran[ans%10]);
			break;
		case 3:
			printf("%s bai",tran2[ans/100]);
			ans %= 100;
			if (ans > 0)
			{
				if (ans > 9)
					printf(" %s shi",tran[ans/10]);
				else 
					printf(" %s",tran[ans/10]);
				ans %= 10;
				if (ans > 0)
					printf(" %s",tran[ans]);
			}
			break;
		case 4:
			printf("%s qian",tran2[ans/1000]);
			ans %= 1000;
			if (ans > 0)
			{
				if (ans > 99)
				{
					printf(" %s bai",tran2[ans/100]);
					ans %= 100;
					if (ans > 0)
					{
						if (ans > 9)
						{
							printf(" %s ",tran[ans/10]);
							printf("shi");
							ans %= 10;
							if (ans > 0)
								printf(" %s",tran[ans]);
						}
						else
						{
							printf(" ling %s",tran[ans]);
						}
					}
				}
				else
				{
					printf(" ling");
					if (ans > 9)
					{
						printf(" %s ",tran[ans/10]);
						printf("shi");
					}
					if (ans%10)
						printf(" %s",tran[ans%10]);
				}
			}
			break;
	}
}

int main()
{
	cin>>A>>n>>B;
	while(n--)
	{
		cin>>jing>>mei>>b13;
		for(int a=A;a>=jing;a--)
			for(int b=B;b>=b13;b--)
				dp[a][b]=max(dp[a][b],dp[a-jing][b-b13]+mei);
	}
	for(int a=0;a<=A;a++)
		for(int b=0;b<=B;b++)
			ans=max(dp[a][b],ans);
	translate(ans);
}