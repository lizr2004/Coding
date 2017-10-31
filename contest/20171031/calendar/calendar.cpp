#include <iostream>
#include <stdio.h>
int R[]={31,29,31,30,31,30,31,31,30,31,30,31};
int P[]={31,28,31,30,31,30,31,31,30,31,30,31};

bool is_it(int year)
{
	if(year==1900)return false;
	else return !(year&1 || year&2);
}
int getdays(int year,int month)
{
	if(is_it(year))return R[month-1];
	else return P[month-1];
}

int main()
{
	freopen("calendar.in","r",stdin);
	freopen("calendar.out","w",stdout);
	int year,month,day,ans;
	while(~scanf("%d%d%d",&year,&month,&day))
	{
	}
}
