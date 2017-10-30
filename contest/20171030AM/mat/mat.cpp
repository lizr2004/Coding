#include <iostream>
#include <map>
#include <stdio.h>
#define ercifang(a) ((a)*(a))
int arr[51200],brr[51200];

int main()
{
	// freopen("mat.in","r",stdin);
	// freopen("mat.out","w",stdout);
	int ansI=0,n=0,m=1;
	double ans=0.0;
	scanf("%d",&n);
	for(int a=1;a<=n;a++) m*=a;
	for(int a=0;a<n;a++) scanf("%d",arr+a);
	for(int a=0;a<n;a++) scanf("%d",brr+a);
	for(int a=0;a<n;a++)
		for(int b=0;b<n;b++)
		{
			if(arr[a]>brr[b]) ans+=ercifang(arr[a]-brr[b]);
			else ans-=ercifang(arr[a]-brr[b]);
		}
	printf("%.1f\n",((double)ans)/m);
}
