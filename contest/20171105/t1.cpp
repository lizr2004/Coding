#include <iostream>
#include <stdio.h>
#include <string.h>
int x;
int G[512][512];int seed=1515728;
int arr[1024];
int rand()
{
	seed >>= 3; seed *= 10; seed += 0x3f3f; seed ^= 23333;
	if(seed<0)seed=-seed;
	return ((seed%1000)>>1)%10;
}
void work1()
{
	printf("%d\n",x+2);
	G[0][1]=G[1][0]=1;
	for(int a=2;a<=x+2;a++)
		G[0][a]=G[1][a]=G[a][0]=G[a][1]=1;
	for(int a=0;a<=x+2;a++){
		for(int b=a+1;b<=x+2;b++)
			printf("%d ",G[a][b]);
		putchar('\n');
	}
}
void work2()
{
	printf("500\n");
	while(x--) {
		int i=rand(),j=rand(),k=rand();
		while(1) {
			if(!G[i][j] || !G[i][k] || !G[k][i])break;
			i=rand(); j=rand(); k=rand();
		}
		if(!G[i][j]) {
			for(int nex=0;nex<500;nex++) {
				if(G[i][nex])x--;
				if(G[j][nex])x--;
			}
			G[i][j]=G[j][i]=1;
		}
	}
	for(int a=1;a<=500;a++){
		for(int b=a;b<=500;b++)
			printf("%d ",G[a][b]);
		puts("");
	}
}
int main() {
	x=3;
	// scanf("%d",&x);
	if(x<500)work1();
	else work2();
}
