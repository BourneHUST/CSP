#include "head.h"

//2020-6-1  AC 2020/09/11
/*
#include <stdio.h>
#include <stdlib.h>
int n, m;  //分别表示点盒查询的个数
const int MAXN = 1000 + 5;

struct Point {
	int i;
	int j;
	char Type;
}p[MAXN];

bool Linear_Test(int w0, int w1, int w2)
{
	int A,B;
	int x;
	if (p[0].Type == 'A')
	{
		A = (w0 + w1 * p[0].i + w2 * p[0].j < 0) ? -1 : 1;
		B = -A;
	}
	else
	{
		B = (w0 + w1 * p[0].i + w2 * p[0].j < 0) ? -1 : 1;
		A = -B;
	}

	for (int i = 1; i < n; i++)
	{
		x = (w0 + w1 * p[i].i + w2 * p[i].j < 0) ? -1 : 1;
		if (p[i].Type == 'A')
		{
			if (x != A)
				return false;
		}
		else
		{
			if (x != B)
				return false;
		}
	}

	return true;
}

int main(void)
{
	//freopen("test.in", "r", stdin);
	int w0, w1, w2;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d%d %c", &p[i].i, &p[i].j, &p[i].Type);

	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &w0, &w1, &w2);
		if (Linear_Test(w0, w1, w2))
			printf("Yes\n");
		else
			printf("No\n");
	}

	return 0;
}
*/

//2020-6-2  AC 2020/9/11
/*
int main(void)
{
    int n,a,b; //n是维度，a,b分别是u,v的非零值个数
    map<int,int> u;  //下标，数据
    map<int,int> v;
    scanf("%d%d%d",&n,&a,&b);
    int pos,val;
    for(int i=0;i<a;i++)
    {
        scanf("%d%d",&pos,&val);
        u[pos]=val;
    }
    for(int i=0;i<b;i++)
    {
        scanf("%d%d",&pos,&val);
        v[pos]=val;
    }

    //类似双指针，map已经根据键排好序
    long long res = 0;
    auto itu = u.begin();
    auto itv = v.begin();

    while(itu!=u.end() && itv != v.end())
    {
         if(itu->first == itv->first)  //位置对应
         {
             res += itu->second * itv->second;
             itu++;
             itv++;
         }
         else if(itu->first < itv->first)
             itu++;
         else
             itv++;
    }

    printf("%lld",res);

    return 0;
}
*/







