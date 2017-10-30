#include <iostream>
#include <stdio.h>
#include <string.h>

int arr[3000];

int main()
{
	freopen("seqdb.out","w",stdout);
	arr[1]=arr[2]=arr[3]=1;
	for(int a=4;a<=200;a++)
		arr[a]=(arr[a-1]+arr[a-3])%1000000007;
	for(int a=1;a<=200;a++)
		printf("%d\n",arr[a]);
	return 0;
}