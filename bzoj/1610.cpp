#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
int n,tot,ans;
double sl[40001];
struct point{double x,y;}a[201];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[i].x!=a[j].x)sl[++tot]=(a[j].y-a[i].y)/(a[j].x-a[i].x);
			else sl[++tot]=1e10;
	std::sort(sl+1,sl+tot+1);
	for(int i=1;i<=tot;i++)
		if(fabs(sl[i]-sl[i-1])>1e-8)ans++;
	printf("%d",ans);
	return 0;
}
