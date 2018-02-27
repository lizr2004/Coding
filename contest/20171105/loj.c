#include <stdio.h>

int main()
{
	freopen("%0.cpp","r",stdin);
	char c;
	while(c=getchar()!=EOF)putchar(c);
}