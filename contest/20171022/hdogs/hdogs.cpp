#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <climits>
inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
int gcd(int a, int b)
{
	int r;
	if (a < b) std::swap(a, b);
	if (!b) return a;
	while ((r = a % b) != 0) {a = b; b = r; }
	return b;
}
int lcm(int a, int b)
{
	if (a && b) return (a / gcd(a, b)) * b;
	else return 0;
}
int main()
{
	freopen("hdogs.in","r",stdin);
	freopen("hdogs.out","w",stdout);
	int T;
	read(T);
	// printf("%d\n",T);
	while(T--)
	{
		int n,m;
		read(n);read(m);
		int l=lcm(n,m);
		int h=(l/n)-1;
		printf("%d\n",h*n);
	}
	return 0;
}
