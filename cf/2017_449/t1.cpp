/*
	Writer:	Lizr2004
	School:	XTYF
	Time:	2017-12-02 22:05:32
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
#include <math.h>
#define qing(arr) memset(arr,0,sizeof(arr))
#define full(arr) memset(arr,-1,sizeof(arr))
#define sinf(arr) memset(arr,0x3f,sizeof(arr))
#define ll long long
using namespace std;
char str[128];
int read(int& in) {
	in=0;char c=getchar(),ch=1;
	while(c<'0' || c>'9'){if(c=='-')ch=-ch; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=ch;
}
ll read(ll& in) {
	in=0;char c=getchar(),ch=1;
	while(c<'0' || c>'9'){if(c=='-')ch=-ch; c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0'; c=getchar();}
	return in*=ch;
}
int main(int argc, char const *argv[])
{
	// freopen("in.txt","r",stdin);
	int n,m;
	read(n);read(m);
	scanf("%s",str);
	for(int a=1;a<=m;a++)
	{
		// puts("FUCK");
		int l,r;scanf("%d%d",&l,&r);l--;r--;
		char c=0,f,t;
		while(c>'z' || c<'a')c=getchar();f=c;c=0;
		while(c>'z' || c<'a')c=getchar();t=c;c=0;
		// printf("%c %c\n",f,t);
		for(int b=l;b<=r;b++){
			// printf("%c %c\n",str[b],f);
			if(str[b]==f)
			{
				// puts("FUCK");
				str[b]=t;
			}
		}
	}
	printf("%s\n",str);
	return 0;
}