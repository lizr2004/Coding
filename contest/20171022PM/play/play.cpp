#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
int get(int& x)
{
	char in[3];
	memset(in,0,sizeof(in));
	while(1)
	{
		in[2]=in[1]; in[1]=in[0]; in[0]=getchar();
		if(in[2]=='h' && in[1]=='o' && in[0]=='m')return x=1;
		else if(in[2]=='a' && in[1]=='w' && in[0]=='a')return x=0;
	}
}

inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}

int main()
{
	freopen("play.in","r",stdin);
	freopen("play.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int now;int n,m;
		get(now);
		read(n);
		read(m);
		if(now)
		{
			if(m-n>m)
				printf("%d ",std::max(0,m-n));
			else 
				printf("%d ",std::max(0,m-n+1));
			printf("%d\n",std::min(30,m+29-n));
		}
		else
		{ 
			if(m-n>m)
				printf("%d ",std::max(0,m-n));
			else 
				printf("%d ",std::max(0,m-n+1));
			printf("%d\n",std::min(30,m+29-n));
		}
	}
	return 0;
}
