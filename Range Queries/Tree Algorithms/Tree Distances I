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
int n;
vector<int> g[sz];
array<int, sz> d1, d2;
void dfs(int u, array<int, sz> &d, int p = -1)
{
    for (int v : g[u])
    {
        if (v == p)
            continue;
        d[v] = d[u] + 1;
        dfs(v, d, u);
    }
}
void Solve()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    fill(d1.begin(), d1.end(), 0);
    int root = 1;
    dfs(root, d1);
    root = max_element(d1.begin(), d1.end()) - d1.begin();
    fill(d1.begin(), d1.end(), 0);
    dfs(root, d1);
    root = max_element(d1.begin(), d1.end()) - d1.begin();
    fill(d2.begin(), d2.end(), 0);
    dfs(root, d2);
    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", max(d1[i], d2[i]), " \n"[i == n]);
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
