#include <iostream>
#include <stdio.h>
#include <string.h>

long long fuck;
char shit[5120];
int sexy[5120][2];
int main()
{
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	scanf("%s%lld",shit,&fuck);fuck--;
	int s=strlen(shit);
	int dx=0,dy=0;
	for(int a=0;a<s;a++)
	{
		switch (shit[a]){
			case 'E': dx++; break;
			case 'S': dy--; break;
			case 'W': dx--; break;
			case 'N': dy++; break;
		}
		sexy[a][0]=dx;
		sexy[a][1]=dy;
	}
	printf("%lld %lld\n",
		(fuck/s)*dx+sexy[fuck%s][0],
		(fuck/s)*dy+sexy[fuck%s][1]
	);
	return 0;
}
