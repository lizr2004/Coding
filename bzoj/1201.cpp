#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct line{
	int d[1086],n;
	void add(int x,int v){d[x]+=v;}
	void build(){for(int i=2;i<=n;i++) d[i]+=d[i-1];}
	bool check(int l,int r){return d[r]-d[l-1]==r-l+1;}
};
line xie1[1086],xie2[1086];
int c[1086][1086];
bool check_shang(int i,int l,int r)
{
	int len=r-l+1;
	return xie1[l].check(i-l+1-len+1,i-l+1)&&xie2[i-r+1].check(r-len+1,r);
}
bool check_xia(int i,int l,int r)
{
	int len=r-l+1;
	return xie2[i-l+2].check(l,l+len-1)&&xie1[r+1].check(i-r+1,i-r+1+len-1);
}
int main()
{
	int n;int x,y,z;
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++)
		xie1[i].n=xie2[i].n=n-i+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
		{
			cin>>x>>y>>z;
			if(x)xie1[j].add(i-j+1,1);
			if(y)xie2[i-j+1].add(j,1);
			c[i][j]=z;
		}
	for(int i=1;i<=n;i++)
		xie1[i].build(),xie2[i].build();
	for(int i=1;i<=n;i++)
	{
		int l=1,r=0;
		for(int j=1;j<=i;j++)
		{
			int z=c[i][j];
			if(z)	r++;
			else	l=j+1,r=j;
			for(int k=l;k<=r;k++)
			{
								ans+=check_shang(i,k,r);
				if(r-k+1<=n-i)	ans+=check_xia(i,k,r);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}