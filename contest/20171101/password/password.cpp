#include <iostream>
#include <stdio.h>
#include <math.h>

inline bool is_prime(int n)
{
	if(n<2)return 0;
	if(n==2)return 1;
	int sq=sqrt(n);
	for(int a=2;a<=sq;a++) if(n%a==0) return 0;
	return 1;
}

int main()
{
	freopen("password.in","r",stdin);
	// freopen("password.out","w",stdout);
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int l,k,tot=0;
		scanf("%d%d",&l,&k);
		l=(1<<l);
		for(int a=1;;a++)
		{
			if(is_prime(a*l+1))tot++;
			if(tot==k){printf("%d\n",a*l+1);break;}
		}
	}
	return 0;
}
