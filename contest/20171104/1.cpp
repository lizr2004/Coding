#include <iostream>
#include <stdio.h>
#include <string.h>

char arr[5000000];
int ans[4194304];
char map[128];
int realans=-1;
int k;
int main() {
	map['A']=1; map['G']=2; map['C']=3; map['T']=0;
	scanf("%s%d",arr,&k);
	int n=strlen(arr);
	register int andnum= (1<<(k*2))-1;
	register int now=0;
	for(int a=0;a<k;a++)now<<=2,now+=map[arr[a]];
	for(int a=0;a<=(n-k);a++) {
		now<<=2;now&=andnum;now+=map[arr[a]];
		ans[now]++;
		realans=std::max(realans,ans[now]);
	}
	printf("%d\n",realans);
}
