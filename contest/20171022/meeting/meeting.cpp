#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
char in[102400];
int main()
{
	freopen("meeting.in","r",stdin);
	freopen("meeting.out","w",stdout);
	int T;
	read(T);
	for(int g=1;g<=T;g++)
	{
		int ans=0;
		memset(in,0,sizeof(in));
		scanf("%s",in+1);
		int n=strlen(in+1);
		for(int a=1;a<=n;a++)
			in[a+n]=(in[a]);
		if(n<3)printf("Case %d: %d\n",g,ans);
		else
		{
			for(int a=1;a<=n;a++)
				if(in[a]==in[a+1] && in[a+1]==in[a+2])
					ans++;
			for(int a=1;a<=n;a++)
			for(int b=2;b<=(n/3);b+=2)
			if(	in[a]==in[a+b] && 
				in[a+b]==in[a+(b<<1)] && 
				((a+(b<<1))%n!=a-b)
			)
				ans++;
			printf("Case %d: %d\n",g,ans);
		}
	}
	return 0;
}