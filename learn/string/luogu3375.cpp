#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

const int N=1048576;

char t[N],s[N];
int next[N];

int main()
{
	scanf("%s%s",s,t);
	int tlen=strlen(t);
	int slen=strlen(s);
	next[0]=-1; int j=0;
	for(int i=1;i<tlen;i++)
	{
		j=next[i-1];
		while(j!=-1 && t[i]!=t[j+1])j=next[j];
		if(t[i]==t[j+1])next[i]=j+1;
		else next[i]=-1;
//		printf("i=%d j=%d\n",i,j);
	}
	j=0;
	for(int i=0;i<slen;i++)
	{
		while(j!=-1 && s[i]!=t[j+1])j=next[j];
		if(s[i]==t[j+1])j++;
		if((j+1)==tlen)
		{
			printf("%d\n",i-tlen+2);
			j=next[j];
		}
//		printf("i=%d j=%d\n",i,j);
	}
	for(int i=0;i<tlen;i++)
		printf("%d ",1+next[i]);
	putchar('\n');
	return 0;
}
