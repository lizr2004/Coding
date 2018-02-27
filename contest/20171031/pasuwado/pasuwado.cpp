#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
std::string arr,ans; int k,l;

void dfs(int dep)
{
	if(dep>=k){ans=std::min(ans,arr);return;}
	for(int a=1;a<l;a++)
	{
		// if(arr[a]>arr[a-1]){
			std::swap(arr[a],arr[a-1]);
			dfs(dep+1);
			std::swap(arr[a],arr[a-1]);
		// }
	}
}
char qiu[102400];
int main()
{
	freopen("pasuwado.in","r",stdin);
	freopen("pasuwado.out","w",stdout);
	scanf("%d",&k);
	std::cin>>arr;ans=arr;
	l=arr.size();
	const char *str=arr.c_str();
	memcpy(qiu,str,sizeof(str));
	// if(l>100){std::sort(qiu,qiu+l);printf("%s\n",qiu);return 0;}
	dfs(0);
	std::cout<<ans<<std::endl;
}
