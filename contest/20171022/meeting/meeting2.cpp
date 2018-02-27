#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <algorithm>
char in[102400];int n;
inline int read(int& x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*=f;
}
// std::map<std::pair<int,int>,bool> ma;
bool tepan(int a,int b,int c){return 0;}
int main()
{
	freopen("meeting.in","r",stdin);
	// freopen("meeting.out","w",stdout);
	int T;
	read(T);
	while(T--)
	{
		int ans=0,tp=0,c;
		memset(in,0,sizeof(in));
		scanf("%s",in+1);
		n=strlen(in+1);
		for(int a=1;a<=n;a++)
			in[a+n]=(in[a]);
		if(n&1)
		{
			for(int a=1;a<=n;a++)
				for(int b=a+1;b<=n;b++)
				{
					if(in[a] != in[b])continue;
					if((a&1) == (b&1))
					{
						c=(a+b)>>1;
						if(tepan(a,b,c))tp++;
						if(in[c]==in[a])
						{
							// printf("%d %d %d\n",a,b,c);
							ans++;
						}
					}
					else
					{
						c=((a+b)%n+n)>>1;
						if(tepan(a,b,c))tp++;
						if(in[c]==in[a])
						{
							// printf("%d %d %d\n",a,b,c);
							ans++;
						}
					}
				}
		} 
		else 
		{
			for(int a=1;a<=n;a++)
				for(int b=a+1;b<=n;b++)
				{
					if(in[a] != in[b])continue;
					if((a&1) == (b&1))
					{
						c=((a+b)%n)>>1;
						if(tepan(a,b,c))tp++;
						if(in[c]==in[a])
						{
							// printf("%d %d %d\n",a,b,c);
							ans++;
						}
						c+=(n>>1);
						if(tepan(a,b,c))tp++;
						if(in[c]==in[a])
						{
							// printf("%d %d %d\n",a,b,c);
							ans++;
						}
					}
				}
		}
		printf("%d %d\n",ans,tp);
	}
	return 0;
}