#include <iostream>
#include <stdio.h>
// #include <math.h>
int arr[512000];

int pow(int a,int b)
{
	int sum=1;
	for(int x=1;x<=b;x++) sum*=a;
	return sum;
}

int main()
{
	freopen("disk.in","r",stdin);
	freopen("disk.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int a=1;a<=n;a++)
		scanf("%d",arr+a);
	while(m--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		switch(a)
		{
			case 1:for(int i=b;i<=c;i++)arr[i]+=d;break;
			case 2:for(int i=b;i<=c;i++)arr[i]=d;break;
			case 3:
			{
				int sum=0;
				for(int i=b;i<=c;i++)
				{
					sum+=pow(arr[i],d);
					if(sum>998244353)
						sum-=998244353;
				}
				printf("%d\n",sum%998244353);
				break;
			}
		}
		// for(int a=1;a<=n;a++)
		// 	printf("%d ",arr[a]);
		// puts("");
	}
}