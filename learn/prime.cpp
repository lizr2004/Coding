#include <stdio.h>
#include <stdlib.h>
#define LL long long 
int read(int& in) {
	in=0;char c=getchar();int cheng=1;
	while(c<'0' || c>'9'){if(c=='-')cheng=-1; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=cheng;
}
LL modular_multi(LL x,LL y,LL mo)
{
	LL t;
	x%=mo;
	for(t=0;y;x=(x<<1)%mo,y>>=1)
		if (y&1)
			t=(t+x)%mo;
	return t;
}

LL modular_exp(LL num,LL t,LL mo)
{
	LL ret=1,temp=num%mo;
	for(;t;t>>=1,temp=modular_multi(temp,temp,mo))
		if (t&1)
			ret=modular_multi(ret,temp,mo);
	return ret;
}

bool miller_rabbin(LL n)
{
	if (n==2)return true;
	if (n<2||!(n&1))return false;
	int t=0;
	LL a,x,y,u=n-1;
	while((u&1)==0) t++,u>>=1;
	for(int i=0;i<10;i++)
	{
		a=rand()%(n-1)+1;
		x=modular_exp(a,u,n);
		for(int j=0;j<t;j++)
		{
			y=modular_multi(x,x,n);
			if (y==1&&x!=1&&x!=n-1)
				return false;
			x=y;
		}
		if (x!=1)
			return false;
	}
	return true;
}
int main(){
	int n;
	read(n);read(n);
	while(n--)
	{
		int now;
		read(now);
		puts(miller_rabbin((LL)now)?"Yes":"No");
	}
}