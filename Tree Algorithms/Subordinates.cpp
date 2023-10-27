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
array<int, sz> d;
void dfs(int u, int p = -1)
{
    d[u] = 1;
    for (int v : g[u])
    {
        if (v == p)
            continue;
        dfs(v, u);
        d[u] += d[v];
    }
}
void Solve()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        g[x].emplace_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        printf("%d%c", d[i] - 1, " \n"[i == n]);
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
