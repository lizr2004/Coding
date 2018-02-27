#include <iostream>
#include <stdio.h>
#include <algorithm>
int n,now=0x3f3f3f3f;
struct data{int x,y;}a[1001];
bool cmp(data a,data b){return a.y<b.y;}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	std::sort(a+1,a+n+1,cmp);
	for(int i=n;i>0;i--)
		now=std::min(now,a[i].y)-a[i].x;
	if(now<0)printf("-1");
	else printf("%d",now);
	return 0;
}
