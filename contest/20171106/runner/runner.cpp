#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
std::vector<int> gra[102400];
int n,m,ans;
int fa[102400];
struct node {int u,v,w;};
node no[1024000];
int du[102400];
// void addedge(int a,int b,int c)
int cha(int now) {if(fa[now]==now)return now; return fa[now]=cha(fa[now]); }
void ji(int ma) {for(int a=1;a<=ma;a++) fa[a]=a; }
bool cmp(node a,node b) {return  a.w<b.w; }
int main(){
	// freopen("runner.in","r",stdin);
	// freopen("runner.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int a=1;a<=m;a++) scanf("%d%d%d",&no[a].u,&no[a].v,&no[a].w);
	ji(m);
	std::sort(no+1,no+m+1,cmp);int tot=0;
	for(int a=1;a<=m;a++)
	{
		int ra=cha(no[a].u);
		int rb=cha(no[a].v);
		if(ra==rb)continue;
		du[ra]++;gra[ra].push_back(rb);
		du[rb]++;gra[rb].push_back(ra);
		ans+=no[a].w;
		fa[ra]=rb;
		tot++;
		if(tot==n-1)break;
	}
	if(tot!=n-1){puts("orz");return 0;}
	printf("%d\n",ans);
	return 0;
	int maxdu=-1,shuyu;tot=0;
	while(1){
		maxdu=-1;
		for(int a=1;a<=n;a++) if(maxdu<du[a]){maxdu=du[a];shuyu=a;}
		if(maxdu==0)break;
		tot++;du[shuyu]=0;
		for (std::vector<int>::iterator i = gra[shuyu].begin(); i != gra[shuyu].end(); ++i)
		{
			for (std::vector<int>::iterator it = gra[*i].begin(); it != gra[*i].end(); ++it)
				if(du[*it]>0)du[*it]--;
			du[*i]-=0;
		}
	}
	printf("%d\n",tot);
}