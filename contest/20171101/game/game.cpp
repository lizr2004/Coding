#include <iostream>
#include <stdio.h>
#include <string.h>
#define qing(a) memset(&(a),0,sizeof(nod));
#define nuo(a,b) memcpy(&(a),&(b),sizeof(nod));
#define nq now.q
#define eq nex.q
using namespace std;
struct nod {char q[4][4];bool who;};
nod yuan;
char getREALchar()
{
	char c;
	while(c=getchar())
	{
		if(c=='x')return 2;
		if(c=='o')return 1;
		if(c=='.')return 0;
	}
	return 0x3f;
}

bool can(nod now)
{
	for(int a=0;a<4;a++)if(nq[a][0]==2 && nq[a][0]==nq[a][1] && nq[a][1]==nq[a][2] && nq[a][2]==nq[a][3])return 1;
	for(int a=0;a<4;a++)if(nq[0][a]==2 && nq[0][a]==nq[1][a] && nq[1][a]==nq[2][a] && nq[2][a]==nq[3][a])return 1;
	if(nq[0][0]==2 && nq[0][0]==nq[1][1] && nq[1][1]==nq[2][2] && nq[2][2]==nq[3][3])return 1;
	if(nq[0][3]==2 && nq[0][3]==nq[1][2] && nq[1][2]==nq[2][1] && nq[2][1]==nq[3][0])return 1;
	return 0;
}

bool dfs(int dep,nod now,int limit)
{
	if(dep>limit)return false;
	getchar();
	int ziji=now.who+1;
	int beiren=!now.who+1;
	// printf("-----------------------\n%d %d %d %d\n",ziji,beiren,dep,limit);
	// for(int a=0;a<4;a++){
	// 	for(int b=0;b<4;b++)
	// 		printf("%d ",nq[a][b]);
	// 	puts("");
	// }
	if(can(now))return 1;
	nod nex;
	for(int a=0;a<4;a++) 
	for(int b=0;b<4;b++)
	if(!nq[a][b])
	{
		nuo(nex,now);
		eq[a][b]=nex.who+1;
		nex.who=nex.who?0:1;
		if(can(nex)){printf("(%d,%d)\n",b,a);return true;}
		// if(dfs(dep+1,nex,limit))
		// {
		// 	 if(dep==1)printf("(%d,%d)\n",a,b);
		// 	return true;
		// }
	}
	return false;
}

int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int a=3;a>=0;a--)for(int b=0;b<4;b++)yuan.q[a][b]=getREALchar();
		yuan.who=1;
		// for(int a=1;;a++)if(
			if(!dfs(1,yuan,100))puts("Paolu");
			// )break;
	}
}