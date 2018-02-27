#include <iostream>
#include <stdio.h>
#include <string.h>
int x[102400],ans;
inline int read(int &in) {
	in=0;char c=getchar(),cheng=1;
	while(c<'0' || c>'9'){if(c=='-')cheng=-1;c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0';c=getchar();}
	return in*=cheng;
}

int main() {
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int a=1;a<=n;a++)scanf("%d",&x[a]);
	printf("%d\n",ans);
}
