#include <iostream>
#include <stdio.h>

int ans[1000086],cnt[1000086],arr[100000];
int maxi=-1;
int main()
{
	int n;
	scanf("%d",&n);
	for(int a=0;a<n;a++)
	{
		scanf("%d",&arr[a]);
		cnt[arr[a]]++;
		maxi=std::max(maxi,arr[a]);
	}
	for(int a=1;a<=maxi;a++)
		if(cnt[a])
			for(int b=a;b<=maxi;b+=a)
				ans[b]+=cnt[a];
	for(int a=0;a<n;a++)
		printf("%d\n",ans[arr[a]]-1);
	return 0;
}
