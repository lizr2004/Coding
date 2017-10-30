#include <iostream>
#include <vector>
using namespace std;

int n,k;
vector<int> bb[1005];
bool vis[1005];
int arr[1005];
int dpa[1005][2];
void dp(int a,int fa)
{
	vis[a]=1;
	dpa[a][0]=0;
	dpa[a][1]=arr[a];
	int sz=bb[a].size();
	for(int b=0;b<sz;b++)
	{
		if(bb[a][b]==fa)continue;
		dp(bb[a][b],a);
		dpa[a][0]+=max(dpa[bb[a][b]][0],dpa[bb[a][b]][1]);
		dpa[a][1]+=dpa[bb[a][b]][0];
	}
}

int main()
{
	vector<int> roots;
	int a,b,ans=0;
	cin>>n>>k;
	for(int a=1;a<=n;a++)
		cin>>arr[a];
	while(k--)
	{
		cin>>a>>b;
		bb[a].push_back(b);
		bb[b].push_back(a);
	}
	for(int a=1;a<=n;a++)
		if(!vis[a])
		{
			dp(a,-1);
			roots.push_back(a);
		}
	int sz=roots.size();
	for(int a=0;a<sz;a++)
	{
		// cout<<roots[a]<<endl;
		ans+=max(dpa[roots[a]][0],dpa[roots[a]][1]);
	}
	cout<<ans<<endl;
}