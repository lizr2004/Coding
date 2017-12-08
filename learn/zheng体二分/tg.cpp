#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#define inf 1000000000
#define mod 1000000007
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,K,T;
int l[300005],r[300005],val[300005];
int p[300005],id[300005],tmp[300005],ans[300005];
vector<int> a[300005];
bool mark[300005];
ll t[300005];
ll query(int x)
{
    ll tmp=0;
    for(int i=x;i;i-=i&-i)tmp+=t[i];
    return tmp;
}
void add(int x,int val)
{
    if(x>m)return;
    for(int i=x;i<=m;i+=i&-i)t[i]+=val;
}
void opera(int k,int f)
{
    if(l[k]<=r[k])
        add(l[k],f*val[k]),add(r[k]+1,f*(-val[k]));
    else
    {
        add(1,f*val[k]),add(r[k]+1,f*(-val[k]));
        add(l[k],f*val[k]);
    }
}
void solve(int l,int r,int L,int R)
{
    if(l>r)return;
    if(L==R)
    {
        for(int i=l;i<=r;i++)
            ans[id[i]]=L;
        return;
    }
    int mid=(L+R)>>1;
    while(T<=mid)T++,opera(T,1);
    while(T>mid)opera(T,-1),T--;
    int cnt=0,now;ll tot;
    for(int i=l;i<=r;i++)
    {
        tot=0;now=id[i];
        for(int j=0;j<a[now].size();j++)
        {
            tot+=query(a[now][j]);
            if(tot>=p[now])break;
        }
        if(tot>=p[now])mark[now]=1,cnt++;
        else mark[now]=0;
    }
    int l1=l,l2=l+cnt;
    for(int i=l;i<=r;i++)
        if(mark[id[i]])tmp[l1++]=id[i];
        else tmp[l2++]=id[i];
    for(int i=l;i<=r;i++)id[i]=tmp[i];
    solve(l,l1-1,L,mid);
    solve(l1,l2-1,mid+1,R);
}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;i++)
    {
        int x=read();a[x].push_back(i);
    }
    for(int i=1;i<=n;i++)p[i]=read();
    K=read();
    for(int i=1;i<=K;i++)
    {
        l[i]=read(),r[i]=read(),val[i]=read();
    }
    K++;
    l[K]=1;r[K]=m;val[K]=inf;
    for(int i=1;i<=n;i++)id[i]=i;
    solve(1,n,1,K);
    for(int i=1;i<=n;i++)
        if(ans[i]!=K)
            printf("%d\n",ans[i]);
        else puts("NIE");
    return 0;
}