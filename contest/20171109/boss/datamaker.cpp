#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctime>
int main()
{
	freopen("boss.in","w",stdout);
	srand((unsigned)time(NULL));
	puts("10");
	for(int a=1;a<=10;a++)
	{
		printf("%d\n",rand()%10000000);
	}
}