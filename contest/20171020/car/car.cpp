#include <iostream>
#include <stdio.h>
#include <map>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
using namespace std;
map<int,bool> ma[40960];
map<pii,bool> ma2;
int ans;
int main()
{
    freopen("car.in","r",stdin);
    freopen("car.out","w",stdout);
    int n;
    int minx=0x3f3f3f3f,maxx=-0x3f3f3f3f;
    scanf("%d",&n);
    while(n--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x+=20000;
        y+=20000;
        minx=min(minx,x);
        maxx=max(maxx,x);
        ma[x][y]=1;
        ma2[mp(x,y)]=1;
        // puts("fuck");
    }
    // printf("%d %d\n",minx,maxx);
    for(int x=minx;x<=maxx;x++)
    {
        // puts("shit fucker");
        // printf("%d %d\n",ma[x].begin(),ma[x].end());
        for(map<int,bool>::iterator it1=ma[x].begin();it1!=ma[x].end();it1++)
        {
            // puts("fuck shit");
            map<int,bool>::iterator it2=it1;
            it2++;
            for(;it2!=ma[x].end();it2++)
            {
                // puts("shit");
                // printf("%d %d %d\n",x,it1->first,it2->first);
                // x=x y=it->first  
                int n;
                pii zs=mp(x,it1->first);
                pii ys=mp(x,it2->first);
                if(!ma2[ys])continue;
                n=ys.second-zs.second;
                pii zx=mp(x+n,it1->first);
                pii yx=mp(x+n,it2->first);
                if(!(n&1))
                {
                    pii shang=mp(x-(n>>1),it1->first+(n>>1));
                    pii xia=mp(x+(n>>1),it1->first+(n>>1));
                    if(ma2[shang] && ma2[xia])
                        ans++;
                }
                if(ma2[zx] && ma2[yx])
                    ans++;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

