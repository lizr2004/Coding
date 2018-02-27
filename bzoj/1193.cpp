#include <iostream>
using namespace std;
int dx[8]={1,1,-1,-1,2,2,-2,-2},dy[8]={2,-2,2,-2,1,-1,1,-1};bool flag=0;
inline int abs(int a)
{
	return (a>0)?a:-a;
}
int dfs(int a,int b,int lim,int dep)
{
	if(flag)return 0x3f3f3f3f;
	if(dep>lim)return 0x3f3f3f3f;
	if(a==0 && b==0)
	{
		flag=1;
		return dep;
	}
	int ans=0x3f3f3f3f;
	for(int x=0;x<8;x++)
		ans=min(dfs(a+dx[x],b+dy[x],lim,dep+1),ans);
	return ans;
}

int main()
{
	int ax,ay,bx,by,x,y,ans=0,tmp=0;
	cin>>ax>>ay>>bx>>by;
	x=abs(bx-ax),y=abs(by-ay);
	while(x+y>=10)
	{
		if(x<y)swap(x,y);
		if(x-4>=2*y)x-=4;
		else x-=4,y-=2;	
		ans+=2;
	}
	for(int limit=1;;limit++)
	{
		if((tmp=dfs(x,y,limit,0))!=0x3f3f3f3f)
		{
			cout<<limit+ans<<endl;
			return 0;
		}
	}
}