#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
struct node {int x,y;};
node no[102400];
int read(int& in)
{
	in=0;char c=getchar();int cheng=1;
	while(c<'0' || c>'9'){if(c=='-')cheng=-1; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=cheng;
}
bool cmp(node a,node b){return a.x<b.x; }
int main() {
	freopen("liuhai.in","r",stdin);
	freopen("liuhai.out","w",stdout);
	long long ans=0.0;
	int n;
	read(n);
	for(int a=1;a<=n;a++){read(no[a].x);read(no[a].y);}
	std::sort(no+1,no+n+1,cmp);
	for(int a=2;a<=n;a++){
		ans+=(no[a].y+no[a-1].y)*(no[a].x-no[a-1].x);
	}
	printf("%.2lf\n",ans/2.0);
}