/*
	Writer:	Lizr2004
	School:	XTYF
	Time:	2017-12-03 12:20:26
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
	freopen("in.txt","r",stdin);
	
	return 0;
}