#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
std::vector<int> v[16];
inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}

int main()
{
	freopen("shirt.in","r",stdin);
	freopen("shirt.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int n;
		read(n);
	}
	return 0;
}