#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
int get(int n)
{
	int ans=0;
	while(n)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}

int main()
{
	std::vector<int> v;
	int n;
	// printf("%d\n",get(15));
	scanf("%d",&n);
	for(int now=std::max(n-100,0);now<=n;now++)
		if((get(now) + now) == n)
			v.push_back(now);
	printf("%d\n",v.size());
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i)
	{
		printf("%d\n",*i);
	}
}
