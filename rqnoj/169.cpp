#include <iostream>
#define maxn 1000
using namespace std;
long dis,a[11],f[maxn],n,i,j;
int main()
{
	for (i=1;i<=10;i++)
		cin>>a[i];
	cin>>dis;
	for (j=1;j<=dis;j++)
	{
		f[j]=0x3f3f3f3f;
		for (i=1;i<=10;i++)
			if (j-i>=0 && f[j-i]+a[i]<f[j])
				f[j]=f[j-i]+a[i];
	}
	cout<<f[dis]<<endl;
	return 0;
} 
