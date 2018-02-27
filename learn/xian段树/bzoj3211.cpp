#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 200000*4
int lson[N],rson[N];
bool flag[N];
long long sum[N];
int root=1,cnt=1;
inline void out(){}
inline void out(int x)
{
	for(int a=1;a<=cnt;a++)printf("%d ",a);putchar('\n');
	for(int a=1;a<=cnt;a++)printf("%d ",lson[a]);putchar('\n');
	for(int a=1;a<=cnt;a++)printf("%d ",rson[a]);putchar('\n');
	for(int a=1;a<=cnt;a++)printf("%d ",flag[a]);putchar('\n');
	for(int a=1;a<=cnt;a++)printf("%lld ",sum[a]);putchar('\n');
}
inline int cal(int& ID)
{
	if(ID==0)ID=++cnt;
	return ID;
}
long long ask(int& ID,int l,int r,int L,int R)
{
	cal(ID);
	if(l>=L && r<=R)return sum[ID];
	cal(lson[ID]);cal(rson[ID]);
	long long ans=0;int mid=(l+r)>>1;
	if(l<=R && mid>=L)ans+=ask(lson[ID],l,mid,L,R);
	if(r>=L && mid<=R)ans+=ask(rson[ID],mid+1,r,L,R);
	return ans;
}
void update(int& ID,int l,int r,int L,int R,int x)
{
	cal(ID);
	if(l==r && l>=L && r<=R)
	{
		sum[ID]=x;
		if(sum[ID]<=1)
		{
			// printf("x=%d %d %d %d %d ID is %d, sum[ID] is %lld\n",x,l,r,L,R,ID,sum[ID]);
			flag[ID]=1;
		}
		return;
	}
	cal(lson[ID]);cal(rson[ID]);
	// if(lazy[ID])pushdown(ID,l,r);
	int mid=(l+r)>>1;
	if(l<=R && mid>=L) update(lson[ID],l,mid,L,R,x);
	if(r>=L && mid<=R) update(rson[ID],mid+1,r,L,R,x);
	sum[ID]=sum[rson[ID]]+sum[lson[ID]];
	flag[ID]=flag[lson[ID]]&flag[rson[ID]];
	return;
}
void update(int& ID,int l,int r,int L,int R)
{
	// printf("ID=%d l=%d r=%d L=%d R=%d\n",ID,l,r,L,R);
	if(flag[ID])return;
	cal(ID);
	if(l==r && l>=L && r<=R)
	{
		sum[ID]=sqrt(sum[ID]);
		if(sum[ID]<=1)flag[ID]=1;
		return;
	}
	cal(lson[ID]);cal(rson[ID]);
	// if(lazy[ID])pushdown(ID,l,r);
	int mid=(l+r)>>1;
	if(l<=R && mid>=L) update(lson[ID],l,mid,L,R);
	if(r>=L && mid<=R) update(rson[ID],mid+1,r,L,R);
	if(l!=r)sum[ID]=sum[rson[ID]]+sum[lson[ID]];
	flag[ID]=flag[lson[ID]]&flag[rson[ID]];
	return;
}

int main()
{
	// freopen("in.txt","r",stdin);
	int n,m;
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
	{
		// puts("start!");
		int now=0;
		scanf("%d",&now);
		update(root,1,n,a,a,now);
		// puts("end!");
	}
	out();
	scanf("%d",&m);
	for(int a=1;a<=m;a++)
	{
		int typ,o1,o2,o3;
		scanf("%d",&typ);
		if(typ==2)
		{
			scanf("%d%d",&o1,&o2);
			update(root,1,n,o1,o2);
		}
		else
		{
			scanf("%d%d",&o1,&o2);
			printf("%lld\n",ask(root,1,n,o1,o2));
		}
		out();
	}
	return 0;
}
