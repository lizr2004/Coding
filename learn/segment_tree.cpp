#include <iostream>
#include <stdio.h>
#define zhong(a,b) ((a+b)>>1)
#define len(a,b) (a-b)
struct Node
{
	int left,right;
	long long value,lazy;
	Node* leftchild;
	Node* rightchild;
};

Node* build(int l,int r)
{
	Node* now = new Node;
	now->left=l;
	now->right=r;
	now->lazy=0;
	if(l+1<r)
	{
		int mid=zhong(l,r);
		now->leftchild = build(l,mid); now->rightchild = build(mid,r);
		now->value = now->leftchild->value + now->rightchild->value;
	}
	else {scanf("%lld",&now->value); now->leftchild = now->rightchild = NULL; }
	return now;
}

inline void nextlazy(Node* now)
{
	if(now->leftchild!=NULL)
	{
		now->leftchild->lazy+=now->lazy;
		now->leftchild->value+=now->lazy*len(now->leftchild->right,now->leftchild->left);
	}
	if(now->rightchild!=NULL)
	{
		now->rightchild->lazy+=now->lazy;
		now->rightchild->value+=now->lazy*len(now->rightchild->right,now->rightchild->left);
	}
	now->lazy=0;
}

long long ask(int th,Node* now)
{
	if(now->left+1 == now->right)return now->value;
	int mid=zhong(now->left,now->right);if(now->lazy)nextlazy(now);
	if(th<mid)return ask(th,now->leftchild)+now->lazy;
	return ask(th,now->rightchild)+now->lazy;
}

void update(int th,int val,Node* now)
{
	if(now->lazy)nextlazy(now);
	if(now->left+1 == now->right) {now->value+=val; return; }
	int mid=zhong(now->left,now->right);
	if(mid>th)update(th,val,now->leftchild);
	else update(th,val,now->rightchild);
	now->value = now->leftchild->value + now->rightchild->value;
}

void update(int l,int r,int v,Node* now)
{
	if(now->left+1 == now->right){now->value+=v; return; }
	if(l==now->left && r==now->right){
		now->lazy+=v; now->value+=v*len(now->right,now->left); return;
	}
	if(now->lazy)nextlazy(now);
	int mid=zhong(now->left,now->right);
	if(l<mid)update(l,std::min(mid,r),v,now->leftchild);
	if(r>=mid)update(std::max(mid,l),r,v,now->rightchild);
	now->value = now->leftchild->value + now->rightchild->value;
}

long long ask(int l,int r,Node* now)
{
	if(now->left==l && now->right==r)return now->value;
	if(now->left+1 == now->right)return now->value;
	if(now->lazy)nextlazy(now);
	int mid=zhong(now->left,now->right);long long ans=0;
	if(l<mid) ans+=ask(l,std::min(mid,r),now->leftchild);
	if(r>=mid) ans+=ask(std::max(mid,l),r,now->rightchild);
	return ans;
}

int main()
{
	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	Node* root = build(1,n+1);
	scanf("%d",&n);
	while(n--)
	{
		int flag,a,b,c;
		scanf("%d",&flag);
		if(flag==1)
		{
			scanf("%d%d%d",&a,&b,&c);
			update(a,b,c,root);
		}
		else
		{
			scanf("%d%d",&a,&b);
			long long main_ans=ask(a,b,root);
			printf("%lld\n",main_ans);
		}
	}
	return 0;
}