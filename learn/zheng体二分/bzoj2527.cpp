/*
	Writer:	Lizr2004
	School:	XTYF
	Time:	2017-12-07 10:21:46
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#define qing(arr) memset(arr,0,sizeof(arr))
#define full(arr) memset(arr,-1,sizeof(arr))
#define sinf(arr) memset(arr,0x3f,sizeof(arr))
#define ll long long
using namespace std;

int read(int& in) {
	in=0;char c=getchar(),ch=1;
	while(c<'0' || c>'9'){if(c=='-')ch=-ch; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=ch;
}
ll read(ll& in) {
	in=0;char c=getchar(),ch=1;
	while(c<'0' || c>'9'){if(c=='-')ch=-ch; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=ch;
}
namespace segtree
{
	const int N=200000;
	int root=1;
	int lson[N],rson[N],cnt=1;
	ll lazy[N],sum[N];
	int cal(int& ID){if(ID==0)ID=++cnt;return ID;}
	void pushdown(int ID,int l,int r)
	{
		if(!lazy[ID])return;
		int mid=(l+r)>>1;
		cal(rson[ID]);cal(lson[ID]);
		lazy[lson[ID]]+=lazy[ID];
		lazy[rson[ID]]+=lazy[ID];
		sum[lson[ID]]+=lazy[ID]*(mid-l+1);
		sum[rson[ID]]+=lazy[ID]*(r-mid);
	}
	ll ask(int ID,int l,int r,int L,int R)
	{
		cal(ID);
		if(L<=l && r<=R)return sum[ID];
		pushdown(ID,l,r); int mid=(l+r)>>1; ll ans=0LL;
		if(R>=l && mid>=L)ans+=ask(lson[ID],l,mid,L,R);
		if(R>=mid+1 && r>=L)ans+=ask(rson[ID],mid+1,r,L,R);
		return ans;
	}
	void update(int ID,int l,int r,int L,int R,int x)
	{
		cal(ID);
		if(L<=l && r<=R)
		{
			sum[ID]+=(r-l+1)*x;
			lazy[ID]+=x;
			return;
		}
		pushdown(ID,l,r);
		if(R>=l && mid>=L)ans+=update(lson[ID],l,mid,L,R,x);
		if(R>=mid+1 && r>=L)ans+=update(rson[ID],mid+1,r,L,R,x);
	}

}
vector<int> con[500000];
int shuyu[500000];

int main(int argc, char const *argv[])
{
	freopen("in.txt","r",stdin);
	
	return 0;
}