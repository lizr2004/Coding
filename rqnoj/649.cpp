#include <iostream>
#include <stdio.h>
#include <math.h>
#include <conio.h>
using namespace std;
int A,B,C,D,E,n;
int tot,ans,now;
bool you[10000];
int arr[10000];
int sum[10000];
int main()
{
	cin>>n>>ans>>A>>B>>C;
	sum[0]=arr[0]=now=D=ans;
	int i;
	for(i=1;i<=n;i++)
	{
		D=(D+A+(C/2))*B%C-(C/2);
		arr[i]=D;
		sum[i]=sum[i-1]+arr[i];
		if(you[D]){break;}
		you[D]=1;
		// printf("%d ",D);
		// getch();
		if(now<=0)
			now=D;
		else
			now+=D;
		ans=max(ans,now);
	}
	if(i==n+1)cout<<ans;
	else
	{
		for(int a=i;a<2*i;a++)
		{
			arr[a]=arr[a-i];
			sum[a]=sum[a-1]+arr[a];
		}
		for(int a=0;a<i;a++)
			for(int b=0;b)
	}
}
