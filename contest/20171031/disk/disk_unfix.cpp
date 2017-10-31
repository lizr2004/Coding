#include <iostream>
#include <stdio.h>
#include <string.h>
#define zhong(a) ((((a)->l)+((a)->r))>>1)
#define len(a) ((a)->r-(a)->l)
#define fang(a) ((a)*(a))

struct Node{int l,r,v[11],lazy;bool lazy_type;Node *lc,*rc;};

inline int pow(int a,int b)
{
	int ans=1;
	while(a)
	{
		if(a&1)ans*=b;
		b*=b;a>>=1;
	}
	return ans;
}
Node *build(int l,int r)
{
	Node *now = new Node;
	now->l=l;
	now->r=r; 
	now->lazy=0;
	now->lazy_type=0;
	if(l+1==r)
	{
		scanf("%d",now->v+1);
		now->lc=now->rc=NULL;
		now->v[2]=now->v[1]*now->v[1];
		now->v[3]=now->v[2]*now->v[1];
		now->v[4]=now->v[3]*now->v[1];
		now->v[5]=now->v[4]*now->v[1];
		now->v[6]=now->v[5]*now->v[1];
		now->v[7]=now->v[6]*now->v[1];
		now->v[8]=now->v[7]*now->v[1];
		now->v[9]=now->v[8]*now->v[1];
		now->v[10]=now->v[9]*now->v[1];
		return now;
	}
	int mid=zhong(now);
	now->lc=build(l,mid);
	now->rc=build(mid,r);
	now->v[1]=now->lc->v[1]+now->rc->v[1];
	now->v[2]=now->lc->v[2]+now->rc->v[2];
	now->v[3]=now->lc->v[3]+now->rc->v[3];
	now->v[4]=now->lc->v[4]+now->rc->v[4];
	now->v[5]=now->lc->v[5]+now->rc->v[5];
	now->v[6]=now->lc->v[6]+now->rc->v[6];
	now->v[7]=now->lc->v[7]+now->rc->v[7];
	now->v[8]=now->lc->v[8]+now->rc->v[8];
	now->v[9]=now->lc->v[9]+now->rc->v[9];
	now->v[10]=now->lc->v[10]+now->rc->v[10];
	return now;
}

void nexlazy(Node *now)
{
	if(!now->lazy)return;
	if(!now->lazy_type)
	{
		if(now->lc!=NULL)
		{
			now->lc->v[2]+=(2*now->lazy*(now->lc->v[1])+len(now->lc)*fang(now->lazy) );
			now->lc->v[1]+=now->lazy*len(now->lc);
			now->lc->lazy+=now->lazy;
		}
		if(now->rc!=NULL)
		{
			now->rc->v[2]+=(2*now->lazy*(now->rc->v[1])+len(now->rc)*fang(now->lazy) );
			now->rc->v[1]+=now->lazy*len(now->rc);
			now->rc->lazy+=now->lazy;
		}
	}
	else
	{
		if(now->lc!=NULL)
		{
			now->lc->v[2]=len(now->lc)*fang(now->lazy);
			now->lc->v[1]=len(now->lc)*now->lazy;
			now->lc->lazy=now->lazy;
			now->lc->lazy_type=1;
		}
		if(now->rc!=NULL)
		{
			now->rc->v[2]=len(now->rc)*fang(now->lazy);
			now->rc->v[1]=len(now->rc)*now->lazy;
			now->rc->lazy=now->lazy;
			now->rc->lazy_type=1;
		}
	}
	now->lazy=0;
	now->lazy_type=0;
}

void copy(int l,int r,int x,Node *now)
{
	if(l==now->l && r==now->r)
	{
		now->lazy+=x;
		now->v[2]+= (2*x*(now->v[1])+x*x*len(now) );
		now->v[1]+=x*len(now);
		return;
	}
	nexlazy(now);
	int mid=zhong(now);
	if(l<mid)copy(l,std::min(mid,r),x,now->lc);
	if(mid>=r)copy(r,std::min(mid,r),x,now->rc);
	now->v[1]=now->lc->v[1]+now->rc->v[1];
	now->v[2]=now->lc->v[2]+now->rc->v[2];
	now->v[3]=now->lc->v[3]+now->rc->v[3];
	now->v[4]=now->lc->v[4]+now->rc->v[4];
	now->v[5]=now->lc->v[5]+now->rc->v[5];
	now->v[6]=now->lc->v[6]+now->rc->v[6];
	now->v[7]=now->lc->v[7]+now->rc->v[7];
	now->v[8]=now->lc->v[8]+now->rc->v[8];
	now->v[9]=now->lc->v[9]+now->rc->v[9];
	now->v[10]=now->lc->v[10]+now->rc->v[10];
}

void fg(int l,int r,int x,Node *now)
{
	if(l==now->l && r==now->r)
	{
		now->lazy=x;now->lazy_type=1;
		now->v[2]=fang(x)*len(now);
		now->v[1]=x*len(now);
		return;
	}
	nexlazy(now);
	int mid=zhong(now);
	if(l<mid)fg(l,std::min(mid,r),x,now->lc);
	if(mid>=r)fg(r,std::min(mid,r),x,now->rc);
	now->v[1]=now->lc->v[1]+now->rc->v[1];
	now->v[2]=now->lc->v[2]+now->rc->v[2];
	now->v[3]=now->lc->v[3]+now->rc->v[3];
	now->v[4]=now->lc->v[4]+now->rc->v[4];
	now->v[5]=now->lc->v[5]+now->rc->v[5];
	now->v[6]=now->lc->v[6]+now->rc->v[6];
	now->v[7]=now->lc->v[7]+now->rc->v[7];
	now->v[8]=now->lc->v[8]+now->rc->v[8];
	now->v[9]=now->lc->v[9]+now->rc->v[9];
	now->v[10]=now->lc->v[10]+now->rc->v[10];
}

int ask(int l,int r,int x,Node *now)
{
	if(now->l==l && now->r==r)return now->v[x];
	nexlazy(now);
	int mid=zhong(now),ans=0;
	if(l<mid)ans+=ask(l,std::min(mid,r),x,now->lc);
	if(mid>=r)ans+=ask(r,std::min(mid,r),x,now->rc);
	now->v[1]=now->lc->v[1]+now->rc->v[1];
	now->v[2]=now->lc->v[2]+now->rc->v[2];
	now->v[3]=now->lc->v[3]+now->rc->v[3];
	now->v[4]=now->lc->v[4]+now->rc->v[4];
	now->v[5]=now->lc->v[5]+now->rc->v[5];
	now->v[6]=now->lc->v[6]+now->rc->v[6];
	now->v[7]=now->lc->v[7]+now->rc->v[7];
	now->v[8]=now->lc->v[8]+now->rc->v[8];
	now->v[9]=now->lc->v[9]+now->rc->v[9];
	now->v[10]=now->lc->v[10]+now->rc->v[10];
	return ans;
}

int main()
{
	int n,m;
	// while(1){
	scanf("%d%d",&n,&m);
	// printf("%d\n",pow(n,m) );}
	Node *root=build(1,n+1);
	while(m--)
	{
		int a,b,c,d;
		scanf("%d%d%d");
		
	}
}