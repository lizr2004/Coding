#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
int n,arr[4][4],brr[4],now=1,minn,rnex,ans=0;
int main()
{
	scanf("%d%d%d%d",&n,brr,brr+1,brr+2);
	n--;
	arr[1][2]=arr[2][1]=brr[0];
	arr[1][3]=arr[3][1]=brr[1];
	arr[2][3]=arr[3][2]=brr[2];
	for(int a=0;a<n;a++)
	{
		minn=0x3f3f3f3f;rnex=-1;
		for(int nex=1;nex<=3;nex++)
		{
			if(nex==now)continue;
			if(minn>arr[now][nex])
			{
				minn=arr[now][nex];
				rnex=nex;
			}
		}
		ans+=arr[now][rnex];
		now=rnex;
	}
	printf("%d\n",ans);
	return 0;
}
