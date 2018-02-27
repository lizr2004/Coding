#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct node {int w,t;};
long long n,ans,fucker;
long long sumtime=0,sumw=0;
node f[102400];
bool C[102400];
bool cmp(node a,node b)
{
	return a.w/a.t<b.w/b.t;
	// return a.w*b.t<b.w*a.t;
	// return a.w*a.t<b.w*b.t;
	// return a.w*a.t>b.w*b.t;
	// return a.w<b.w;
}
int main(){
	scanf("%lld",&n);
	for(int a=1;a<=n;a++) {
		scanf("%d%d",&f[a].w,&f[a].t);
		sumtime+=f[a].t;
		sumw+=f[a].w;
	}
	sort(f+1,f+n+1,cmp);
	ans=sumw*sumtime;
	for(int a=1;a<=n;a++){
		ans-=(sumtime)*f[a].w;
		sumtime-=(f[a].t<<1);
	}
	printf("%lld\n",ans);
}
