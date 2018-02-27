#include <iostream>
#include <stdio.h>
#include <string.h>
inline int read(long long& x) {
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
inline int read(int& x) {
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
int s[1024];
long long arr[1024];
int k,maxi=-1;
int main() {
	int n; read(n);
	for(int a=1;a<=n;a++){read(s[a]);maxi=std::max(maxi,s[a]);}
	int m;read(m);
	while(m--) {
		read(arr[0]);read(arr[1]);read(k);
		long long maxans=-1,maxs=-1,minans=0x3f3f3f3f3f3f3f3fLL,mins=-1;
		for(int a=2;a<=maxi;a++) arr[a]=arr[a-1]*k+arr[a-2];
		for(int a=1;a<=n;a++)
		{
			if(arr[s[a]]>maxans)maxans=arr[s[a]],maxs=s[a];
			if(arr[s[a]]<minans)minans=arr[s[a]],mins=s[a];
		}
		printf("%lld %lld\n",maxs,mins);
	}
}