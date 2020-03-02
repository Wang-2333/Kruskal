#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int MaxN = 1e5;
const int Inf = 1 << 30;
typedef struct
{
    int u, v, w;//连接u,v两点权值为w的边
} Power;

Power edge[MaxN + 5];
Power res[MaxN + 5];
int father[MaxN + 5];
int n, m;//点和边的数量

//按权值升值排序
bool cmp(Power a, Power b)
{
    return a.w < b.w;
}

//找到x的父节点
int Find(int x)
{
    if (father[x] == x) return x;
    else return father[x] = Find(father[x]);
}

int main()
{
    scanf_s("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) father[i] = i;
    for (int i = 1; i <= m; i++)
    {
        scanf_s("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    sort(edge + 1, edge + 1 + m, cmp);    //将边按权值排序
    int ans = 0, cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int u = edge[i].u, v = edge[i].v, w = edge[i].w;
        if (Find(u) != Find(v))   //判断是否在同一棵树上
        {
            father[Find(u)] = Find(v);
            ans += w;
            cnt++;
            res[cnt].u = u; res[cnt].v = v; res[cnt].w = w;  //合并集合
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= cnt; i++)
    {
        printf("%d %d %d\n", res[i].u, res[i].v, res[i].w);
    }
    return 0;
}