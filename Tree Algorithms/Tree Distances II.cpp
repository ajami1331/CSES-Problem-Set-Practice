#ifndef solution_h
#define solution_h 1
#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <unordered_map>
#include <utility>
#include <vector>
namespace solution
{
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int sz = 2e5 + 105;
int n, m;
vector<int> g[sz];
array<ll, sz> d, l;
void dfs(int u, int p = -1)
{
    d[u] = 1;
    l[u] = 0;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        d[u] += d[v];
        l[u] += l[v] + d[v];
    }
}
void process(int u, int p = -1)
{
    if (p != -1)
    {
        l[u] = l[p] + n - 2 * d[u];
    }
    for (int v : g[u])
    {
        if (v == p)
            continue;
        process(v, u);
    }
}
void Solve()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    d.fill(0);
    l.fill(0);
    dfs(1);
    process(1);
    for (int i = 1; i <= n; i++)
    {
        printf("%lld%c", l[i], " \n"[i == n]);
    }
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
