#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;

map<pair<int,int>,bool> ha;

int hash1(char *str)
{
	if(str[0]==0)return 0;
	return hash1(str+1)*26+str[0]-'a';
}

int hash2(char *str)
{
	if(str[0]==0)return 0;
	return hash2(str-1)*26+str[0]-'a';
}

char in[2048];

int main()
{
	int n,k=0;
	scanf("%d",&n);
	for(int a=1;a<=n;a++)
	{
		memset(in,0,sizeof(in));
		scanf("%s",in+1);
		int h1=hash1(in+1);
		int h2=hash2(in+strlen(in+1));
//		printf("%d %d\n",h1,h2);
		if(ha[make_pair(h1,h2)])k++;
		ha[make_pair(h1,h2)]=1;
	}
	printf("%d\n",n-k);
}
