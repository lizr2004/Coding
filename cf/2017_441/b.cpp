#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
int arr[100086];
std::vector<int> vs[100086];
int n,k,m;
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int a=0;a<n;a++)
	{
		int now;
		scanf("%d",&now);
		vs[now%m].push_back(now);
	}
	for(int a=0;a<m;a++)
		if(vs[a].size()>=k)
		{
			int tot=0;
			puts("Yes");
			for (std::vector<int>::iterator i = vs[a].begin(); i != vs[a].end(); ++i)
			{
				printf("%d ",*i);tot++;if(tot>=k)return 0;
			}
			return 0;
		}
	puts("No");
	return 0;
}
