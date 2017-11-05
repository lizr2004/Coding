#include <iostream>
#include <stdio.h>
#include <string.h>
#define qing(a) memset(a,0,sizeof(a))
const int MOD=1000000007;
struct mat
{
	long long a[3][3];
};

long long ycd_arr[3][3]={
	{0LL,1LL,0LL},
	{0LL,0LL,1LL},
	{1LL,0LL,1LL}
};
mat multi(mat a,mat b){
	mat c;qing(c.a);
	for(int i=0;i<3;i++)
	for(int j=0;j<3;j++) {
		c.a[i][j]=0;
		for(int k=0;k<3;k++)
			c.a[i][j]+=a.a[i][k]*b.a[k][j]%MOD;
		c.a[i][j]%=MOD;
	}
	return c;
}
void out(mat fuck)
{
	for(int a=0;a<3;a++)
	{
		for(int b=0;b<3;b++)
			printf("%lld ",fuck.a[a][b]);
		puts("");
	}
}
void mat_pow(int n)
{
	mat c,res;
	qing(res.a);memcpy(c.a,ycd_arr,sizeof(ycd_arr));
	for(int i=0;i<3;i++) res.a[i][i]=1;	
	while(n)
	{
		if(n&1) res=mat_mul(res,c);
		c=mat_mul(c,c);
		n>>=1;
		// out(res);puts("-------");out(c);
		// puts("+++++++++++++++++++++++");
	}
	printf("%lld\n",res.a[0][1]);
}
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	int T,fuck;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&fuck);
		mat_pow(fuck+3);
	}
}