#include <iostream>
#include <stdio.h>

bool dp[51200];
int main()
{
	int C,H,maxi=1,now;
	scanf("%d%d",&C,&H);
	dp[0]=1;
	while(H--)
	{
		scanf("%d",&now);
		maxi+=now;
		if(maxi>C)maxi=C;
		for(int a=(maxi-now);a>=0;a--)
			if(dp[a])
				dp[a+now]=1;
	}
	do{
		if(dp[C])
		{
			printf("%d\n",C);
			return 0;
		}
	}while(C--);
}