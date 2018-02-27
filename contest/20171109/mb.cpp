#include <iostream>
#include <stdio.h>
#include <string.h>

inline int read(int &in) {
	in=0;char c=getchar(),cheng=1;
	while(c<'0' || c>'9'){if(c=='-')cheng=-1;c=getchar();}
	while(c>='0' && c<='9'){in=in*10+c-'0';c=getchar();}
	return in*=cheng;
}

int main() {
	
}
