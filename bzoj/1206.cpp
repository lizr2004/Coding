/*
Description
a. 首先在内存中查找，如果该页位于内存中，查找成功，转d，否则继续下面的操作
b. 寻找内存中是否存在空页（即没有装载任何数据页的页面），若有，则从外存中读入要查找页，并将该页送至内存中的空页进行存储，然后转d，否则继续下面的操作；
c. 在内存中寻找一个访问次数最少的页面（如果存在多个页面的访问次数同时为最少，则选取最早读入数据进入内存的那个页面），从外存中读入要查找页，替换该页。
d. 结束所谓访问次数是指从当前页面进入内存到该时刻被访问的次数，如果该页面以前进入过内存并被其它页面替换，那么前面的访问次数不应计入这个时刻的访问次数中
你的任务是设计一个程序实现上述算法。测试数据将会提供m条读写内存的命令，每条命题提供要求访问的虚拟内存页的编号P。你的程序要求能够模拟整个m条命令的全部执行过程，所有的命令是按照输入的先后执行的，最开始的时候内存中的n页全为空。
Input
第1行为n<10000和m<1000000，分别表示内存页数和读写内存命令条数。接下来有m行，其中第i+1行有一个正整数Pi<=10^9，表示第i条读写内存命令需要访问的虚拟内存页的编号。
Output
仅包含一个正整数，表示在整个模拟过程中，在内存中直接查找成功的次数（即上面的算法只执行步骤a的次数）。
Sample Input
3 8 1 1 2 3 4 2 5 4
Sample Output
1
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int nc[1000010];
int n,m;
int p[1000010],pi[1000010];
int num=0;int cnt;
int ans=0;
struct data{
	int dat,tim,sx;//dat是表示值，tim表示访问次数，sx表示先后顺序 
	bool operator > (const data  &other) const
		{
			if (tim<other.tim) return 0;
			if (tim>other.tim) return 1;
			return sx>other.sx; 
		}
};
priority_queue <data,vector<data>,greater<data> > q;

//查找内存，查找成功，结束，答案+1 
//查找失败，查找空页，有空页，插入空页中 结束 
//无空页，删除访问数最小的页，插入此页 结束 
int erfen(int x)
{
	int left=1,right=cnt;
	while (left<=right)
	{
		int mid=(left+right)>>1;
		if(p[mid]==x)	return mid;
		if(p[mid] >x)	right=mid-1;
				 else	left=mid+1;
	}
}
void lsh()
{
	sort(p+1,p+m+1);
	cnt=1;
	for (int i=2; i<=m; i++)
		if (p[i]!=p[i-1]) p[++cnt]=p[i];
	for (int i=1; i<=m; i++)
		pi[i]=erfen(pi[i]);
}
int main()
{
	cin>>n>>m;
	for (int i=1; i<=m; i++)
	{
		cin>>p[i];
		pi[i]=p[i];
	}
	lsh();
	for (int i=1; i<=m; i++)
	{
		int now=pi[i];
		int tmp;
		nc[now]++;
		if (nc[now]>1) {ans++;continue;}//command a.
		data x;
		x.dat=now,x.tim=1,x.sx=i;
		if (q.size()<n) {q.push(x);continue;}//command b.
		data y;
		y=q.top();
		while (y.tim!=nc[y.dat])
		{
			q.pop();
			y.tim=nc[y.dat];
			q.push(y);
			y=q.top();
		}
		nc[y.dat]=0;
		q.pop();q.push(x);//command c.
	}
	printf("%d\n",ans);
	return 0;
}