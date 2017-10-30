/*
Description
a. �������ڴ��в��ң������ҳλ���ڴ��У����ҳɹ���תd�������������Ĳ���
b. Ѱ���ڴ����Ƿ���ڿ�ҳ����û��װ���κ�����ҳ��ҳ�棩�����У��������ж���Ҫ����ҳ��������ҳ�����ڴ��еĿ�ҳ���д洢��Ȼ��תd�������������Ĳ�����
c. ���ڴ���Ѱ��һ�����ʴ������ٵ�ҳ�棨������ڶ��ҳ��ķ��ʴ���ͬʱΪ���٣���ѡȡ����������ݽ����ڴ���Ǹ�ҳ�棩��������ж���Ҫ����ҳ���滻��ҳ��
d. ������ν���ʴ�����ָ�ӵ�ǰҳ������ڴ浽��ʱ�̱����ʵĴ����������ҳ����ǰ������ڴ沢������ҳ���滻����ôǰ��ķ��ʴ�����Ӧ�������ʱ�̵ķ��ʴ�����
������������һ������ʵ�������㷨���������ݽ����ṩm����д�ڴ�����ÿ�������ṩҪ����ʵ������ڴ�ҳ�ı��P����ĳ���Ҫ���ܹ�ģ������m�������ȫ��ִ�й��̣����е������ǰ���������Ⱥ�ִ�еģ��ʼ��ʱ���ڴ��е�nҳȫΪ�ա�
Input
��1��Ϊn<10000��m<1000000���ֱ��ʾ�ڴ�ҳ���Ͷ�д�ڴ�������������������m�У����е�i+1����һ��������Pi<=10^9����ʾ��i����д�ڴ�������Ҫ���ʵ������ڴ�ҳ�ı�š�
Output
������һ������������ʾ������ģ������У����ڴ���ֱ�Ӳ��ҳɹ��Ĵ�������������㷨ִֻ�в���a�Ĵ�������
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
	int dat,tim,sx;//dat�Ǳ�ʾֵ��tim��ʾ���ʴ�����sx��ʾ�Ⱥ�˳�� 
	bool operator > (const data  &other) const
		{
			if (tim<other.tim) return 0;
			if (tim>other.tim) return 1;
			return sx>other.sx; 
		}
};
priority_queue <data,vector<data>,greater<data> > q;

//�����ڴ棬���ҳɹ�����������+1 
//����ʧ�ܣ����ҿ�ҳ���п�ҳ�������ҳ�� ���� 
//�޿�ҳ��ɾ����������С��ҳ�������ҳ ���� 
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