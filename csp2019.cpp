//#include "head.h"

/*
//2019-12-1
int m[4] = {0};
int n;

bool judge(int n) //判断是否是7的倍数或者包含7
{
    if (n % 7 == 0)
        return true;
    else
    {
        while (n != 0)
        {
            if (n % 10 == 7)
                return true;
            n /= 10;
        }
    }
    return false;
}

int main(void)
{
    //freopen("test.in", "r", stdin);
    scanf("%d", &n);
    int count = 0; //计算总共报了几次，不计跳过的次数
    int c = 0;     //模拟报数过程，包括跳过的

    while (count < n) //模拟报数过程
    {
        printf("count = %d\n", count);
        c++;
        if (judge(c))  //如果跳过，count不加
        {
            m[(c - 1) % 4]++;
        }
        else
        {
            count++;
        }
    }
    for (int i = 0; i < 4; i++)
        printf("%d\n", m[i]);
    getchar();
    return 0;
}


#include <stdio.h>
//2019-12-2  50分程序  不能用矩阵存，坐标范围太大
const int MAXN = 500;
int n;                     //已经查明的垃圾点个数
int num[5] = {0};          //回收站选址个数
int pos[MAXN][MAXN] = {0}; //0表示没有垃圾站


bool judge(int x, int y)
{
    if (pos[x][y] && pos[x + 1][y] && pos[x - 1][y] && pos[x][y - 1] && pos[x][y + 1])
        return true;
    return false;
}

void grade(int x, int y)
{
    int Grade = 0;
    if (judge(x, y))
    {
        if (pos[x + 1][y + 1])
            Grade++;
        if (pos[x + 1][y - 1])
            Grade++;
        if (pos[x - 1][y + 1])
            Grade++;
        if (pos[x - 1][y - 1])
            Grade++;
        num[Grade]++;
    }
}

int main(void)
{
    freopen("test.in", "r", stdin);
    scanf("%d", &n);
    int x, y;
    //int m
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        pos[x][y] = 1;
    }
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
        {
            if (pos[i][j])
                grade(i, j);
        }
    for (int i = 0; i < 5; i++)
        printf("%d\n", num[i]);
    // getchar();
    return 0;
}


//改进如下 使用map存储坐标,map访问不存在的键结果是0，不会崩

//2019-12-2  AC 2020/9/11
#include <stdio.h>
#include <map>
using namespace std;

int n;            //已经查明的垃圾点个数
int num[5] = {0}; //回收站选址个数
map<pair<int, int>, int> m;

bool judge(int x, int y)
{
    if (m.find(make_pair(x, y)) == m.end() || m.find(make_pair(x + 1, y)) == m.end() || m.find(make_pair(x - 1, y)) == m.end() || m.find(make_pair(x, y + 1)) == m.end() || m.find(make_pair(x, y - 1)) == m.end())
        return false;
    // if (pos[x][y] && pos[x + 1][y] && pos[x - 1][y] && pos[x][y - 1] && pos[x][y + 1])
    //    return true;
    return true;
}

void grade(int x, int y)
{
    int Grade = 0;
    //printf("x=%d y=%d\n", x, y);
    if (judge(x, y))
    {
        if (m.find(make_pair(x + 1, y + 1)) != m.end())
            Grade++;
        if (m.find(make_pair(x + 1, y - 1)) != m.end())
            Grade++;
        if (m.find(make_pair(x - 1, y + 1)) != m.end())
            Grade++;
        if (m.find(make_pair(x - 1, y - 1)) != m.end())
            Grade++;
        num[Grade]++;
    }
}

int main(void)
{
    freopen("test.in", "r", stdin);
    scanf("%d", &n);

    int x, y;
    //int m
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x, &y);
        m[make_pair(x, y)] = 1;
    }

    for (auto it = m.begin(); it != m.end(); it++)
        grade(it->first.first, it->first.second);

    for (int i = 0; i < 5; i++)
        printf("%d\n", num[i]);
    // getchar();
    return 0;
}


CCF201912-2 回收站选址 

#include <bits/stdc++.h>
using namespace std;
const int N = 1000;
pair<int, int> p[N];
const int CN = 4;
int cnt[CN + 1];

int main()
{
    int n;
    map<pair<int, int>, int> ps;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);

        p[i] = make_pair(x, y);
        ps[p[i]] = 1;
    }

    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++)
    {
        int x = p[i].first;
        int y = p[i].second;

        if (ps[make_pair(x, y - 1)] && ps[make_pair(x, y + 1)] &&
            ps[make_pair(x - 1, y)] && ps[make_pair(x + 1, y)])
            cnt[ps[make_pair(x - 1, y - 1)] + ps[make_pair(x - 1, y + 1)] +
                ps[make_pair(x + 1, y - 1)] + ps[make_pair(x + 1, y + 1)]]++;
    }

    for (int i = 0; i <= CN; i++)
        printf("%d\n", cnt[i]);

    return 0;
}
*/

//201909-1 AC 2020/9/11
/*
#include <stdio.h>
#include <stdlib.h>

int N, M;
int totalnum = 0;

int main(void)
{
    freopen("test.in", "r", stdin);
    int T = 0, k = 1000, P = 0;
    //int maxid, maxnum = 0;
    scanf("%d%d", &N, &M);
    int prenum;
    int loss;
    int lossnum;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &prenum);
        totalnum += prenum;
        lossnum = 0;
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &loss);
            lossnum += abs(loss);
        }
        totalnum -= lossnum;
        if (lossnum == P)
        {
            if (i + 1 < k)
                k = i + 1;
        }
        else if (lossnum > P)
        {
            P = lossnum;
            k = i + 1;
        }
        // printf("lossnum = %d\n", lossnum);
        // printf("totalnum = %d\n", totalnum);
    }
    printf("%d %d %d", totalnum, k, P);
    return 0;
}
*/

//201909-2 AC 2020/09/11   负数取整一定要加上模数N，不然还是个负数

/*
#include <stdio.h>
#include <stdlib.h>

int N, M;
int T = 0;         //全部疏果操作后苹果总数
int D[1005] = {0}; //掉落的苹果树数量
int E = 0;         //相邻三棵树都发生掉落

int main(void)
{
    freopen("test.in", "r", stdin);
    scanf("%d", &N);

    int prenum; //每棵树最开始统计的苹果数量
    int x;
    int loss; //单次掉落数量
    //int total_loss;  //每棵树总共掉落数量

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &M); //M次操作
        scanf("%d", &prenum);
        for (int j = 0; j < M - 1; j++)
        {
            scanf("%d", &x); //有可能是统计也可能是掉落
            if (x <= 0)      //是掉落
            {
                prenum += x; //为了判断是否掉落，要更新
            }
            else //是统计
            {
                if (prenum > x) //实际统计数目小于应有数
                {
                    D[i] = 1;   //掉落标记
                    prenum = x; //更新
                }
            }
        }

        T += prenum;

        //printf("round%d is over\n\n", i + 1);
    }

    int count = 0;
    for (int i = 0; i < N; i++)
        count += D[i];

    for (int i = 0; i < N; i++)
    {
        //printf("i=%d %d %d  %d %d %d\n",i, (i - 1 + N) % N, (i + 1) % N, D[i], D[(i - 1) % N], D[(i + 1) % N]);
        if (D[i] && D[(i - 1 + N) % N] && D[(i + 1) % N])
            E++;
    }

    printf("%d %d %d", T, count, E);
    return 0;
}
*/

//201903-1  AC 2020/9/12
/*
#include <stdio.h>
#include <limits.h>
using namespace std;

int n;
int MAXX = INT_MIN;
int MINX = INT_MAX;
int mid = 0;

int main(void)
{
    //freopen("test.in", "r", stdin);
    int x;
    int flag = 0;
    scanf("%d", &n);
    if (n % 2)
        flag = 1; //flag == 1表示奇数
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        //printf("x = %d\n", x);
        if (i == n / 2 - 1 && !flag)
        {
            mid += x;
            //printf("hhh\n");
        }
        if (i == n / 2)
        {
            //printf("x = %d\n", x);
            mid += x;
            //printf("mid = %d\n", mid);
        }
        if (x > MAXX)
            MAXX = x;
        if (x < MINX)
            MINX = x;
    }

    double res;
    int c = 0;

    if (!flag) //n为偶数
    {
        res = mid / 2.0;
        if (res - int(res) > 0) //是小数
            c = 1;
    }

    if (flag) //n为奇数
    {
        if (mid > MINX)
            printf("%d %d %d", MAXX, mid, MINX);
        else
            printf("%d %d %d", MAXX, MINX, mid);
    }

    else
    {
        if (c)
        {
            if (res > MINX)
                printf("%d %.1f %d", MAXX, res, MINX);
            else
                printf("%d %d %.1f", MAXX, res, res);
        }
        else
        {
            if (mid > MINX)
                printf("%d %d %d", MAXX, mid / 2, MINX);
            else
                printf("%d %d %d", MAXX, MINX, mid / 2);
        }
    }
    return 0;
}
*/

//201903-2  AC 2020/9/12
/*
#include <stdio.h>
#include <stack>
using namespace std;

int N;

bool IsSymbol(char c)
{
    if (c == '+' || c == '-' || c == 'x' || c == '/')
        return true;
    return false;
}

int cal(char op, int a, int b) //a是第一操作数
{
    if (op == 'x')
        return a * b;
    else if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else
        return a / b;
}

bool Judge_24(char *str)
{
    stack<int> val;     //数据栈，最后输出的就是结果
    stack<char> symbol; //符号栈，存四个运算符+，-，x,/
    int i = 0;
    while (str[i] != '\0')
    {
        if (IsSymbol(str[i]))
        {
            if (str[i] == '+' || str[i] == '-')
            {
                if (symbol.empty())
                    symbol.push(str[i]);
                else
                {
                    char c = symbol.top();
                    symbol.pop();
                    int b = val.top();
                    val.pop();
                    int a = val.top();
                    val.pop();
                    val.push(cal(c, a, b));
                    symbol.push(str[i]);
                }
            }

            else //符号是乘除
            {
                if (symbol.empty())
                    symbol.push(str[i]);
                else
                {
                    char c = symbol.top();
                    if (c == '+' || c == '-')
                        symbol.push(str[i]);
                    else
                    {
                        symbol.pop();
                        int b = val.top();
                        val.pop();
                        int a = val.top();
                        val.pop();
                        val.push(cal(c, a, b));
                        symbol.push(str[i]);
                    }
                    //symbol.pop();
                }
            }
        }
        else
            val.push(str[i] - '0');
        i++;
    }

    while (!symbol.empty())
    {
        char c = symbol.top();
        symbol.pop();
        int b = val.top();
        val.pop();
        int a = val.top();
        val.pop();
        val.push(cal(c, a, b));
    }

    if (val.top() == 24)
        return true;
    return false;
}

int main(void)
{
    freopen("test.in", "r", stdin);
    scanf("%d", &N);
    char s[8] = {'\0'};
    for (int i = 0; i < N; i++)
    {
        scanf("%s", s);
        if (Judge_24(s))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
*/
