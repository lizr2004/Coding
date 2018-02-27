#include <iostream>
#include <stdio.h>

bool one[11];
bool two[11];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int a=0;a<n;a++)
	{
		int now;
		scanf("%d",&now);
		one[now]=1;
	}
	for(int a=0;a<m;a++)
	{
		int now;
		scanf("%d",&now);
		two[now]=1;
	}
	for(int a=1;a<200;a++)
	{
		if((one[a%10] || one[a/10]) && (two[a%10] || two[a/10]))
		{
			printf("%d\n",a);
			return 0;
		}
	}
}