#include <iostream>
#include <stdio.h>

char nl[128][32];
char na[1024][1024];
int  nll[128];
int  nal[1024];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int a=0;a<n;a++)
	{
		scanf("%s",nl[a]);
		for(int b=0;;b++)
		{
			if(nl[a][b]) if(nl[a][b]<'a') nl[a][b]=nl[a][b]+'a'-'A';
			else {nll[a]=b; /*len<b*/ break; }
		}
	}
	for(int a=0;a<n;a++)
	{
		scanf("%s",na[a]);
		for(int b=0;;b++)
		{
			if(na[a][b]) if(na[a][b]<'a') na[a][b]=na[a][b]+'a'-'A';
			else {nal[a]=b; /*len<b*/ break; }
		}
	}
	for(int nax=0;nax<n;nax++)
		for(int nlx=0;nlx<m;nlx++)
		{
			int finger_one=0,finger_two=0;
			while(finger_one<nll[])
				
		}
}