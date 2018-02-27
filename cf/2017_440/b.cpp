#include <iostream>
#include <stdio.h>
int arr[102400];
int brr[102400];
int crr[102400];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1)
	{
		int ans=0x3f3f3f3f;
		for(int a=0;a<n;a++)
		{
			int now;
			scanf("%d",&now);
			ans=std::min(now,ans);
		}
		printf("%d",ans);
	}
	else if(k==2)
	{
		int minm=0x3f3f3f3f;
		for(int a=0;a<n;a++)
			scanf("%d",arr+a);
		for(int a=0;a<n;a++)
		{
			minm=std::min(minm,arr[a]);
			brr[a]=minm;
		}minm=0x3f3f3f3f;
		for(int a=n-1;a>=0;a--)
		{
			minm=std::min(minm,arr[a]);
			crr[a]=minm;
		}minm=-0x3f3f3f3f;
		// for(int a=0;a<n;a++)
		// 	printf("%d ",brr[a]);
		// puts("");
		// for(int b=0;b<n;b++)
		// 	printf("%d ",crr[b]);
		for(int a=1;a<n;a++)
		{
			minm=std::max(minm,std::max(brr[a-1],crr[a]));
		}
		printf("%d",minm);
	}
	else
	{
		int ans=-0x3f3f3f3f,now;
		for(int a=0;a<n;a++)
		{ 
			scanf("%d",&now);
			ans=std::max(now,ans);
		}
		printf("%d",ans);
	}
	puts("");
	return 0;
}