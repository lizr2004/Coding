#include <iostream>
#include <stdio.h>
#include <string.h>
#define N 200000*4
int lson[N],rson[N];
long long sum[N],lazy[N];
int root=1,cnt=1;
inline int cal(int& ID)
{
	if(ID==0)ID=++cnt;
	return ID;
}
inline void pushdown(int ID,int l,int r)
{
	int mid=(l+r)>>1;
	sum[lson[ID]]+=(lazy[ID]*(mid-l+1));
	lazy[lson[ID]]+=lazy[ID];
	sum[rson[ID]]+=(lazy[ID]*(r-mid));
	lazy[rson[ID]]+=lazy[ID];
	lazy[ID]=0;
}
long long ask(int& ID,int l,int r,int L,int R)
{
	cal(ID);
	if(l>=L && r<=R)return sum[ID];
	cal(lson[ID]);cal(rson[ID]);
	if(lazy[ID])pushdown(ID,l,r);
	long long ans=0;int mid=(l+r)>>1;
	if(l<=R && mid>=L)ans+=ask(lson[ID],l,mid,L,R);
	if(r>=L && mid<=R)ans+=ask(rson[ID],mid+1,r,L,R);
	sum[ID]=sum[rson[ID]]+sum[lson[ID]]+lazy[ID]*(r-l+1);
	return ans;
}

void update(int& ID,int l,int r,int L,int R,int x)
{
	cal(ID);
	if(l>=L && r<=R)
	{
		sum[ID]+=(x)*(r-l+1);
		lazy[ID]+=x;
		return;
	}
	cal(lson[ID]);cal(rson[ID]);
	if(lazy[ID])pushdown(ID,l,r);
	int mid=(l+r)>>1;
	if(l<=R && mid>=L) update(lson[ID],l,mid,L,R,x);
	if(r>=L && mid<=R) update(rson[ID],mid+1,r,L,R,x);
	sum[ID]=sum[rson[ID]]+sum[lson[ID]]+lazy[ID]*(l-r+1);
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
	{
		int now;
		scanf("%d",&now);
		update(root,1,n,a,a,now);
	}
	scanf("%d",&m);
	for(int a=1;a<=m;a++)
	{
		int typ,o1,o2,o3;
		scanf("%d",&typ);
		if(typ==1)
		{
			scanf("%d%d%d",&o1,&o2,&o3);
			update(root,1,n,o1,o2,o3);
		}
		else
		{
			scanf("%d%d",&o1,&o2);
			printf("%lld\n",ask(root,1,n,o1,o2));
		}
	}
	return 0;
}
