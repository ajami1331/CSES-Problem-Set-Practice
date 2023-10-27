#ifndef BpmHopcraft_h
#define BpmHopcraft_h 1
#include <algorithm>
#include <vector>
namespace library
{
template <size_t MAXN1, size_t MAXN2, size_t MAXM> struct BpmHopcraft
{
    int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
    int matching[MAXN2], dist[MAXN1], Q[MAXN1];
    bool used[MAXN1], vis[MAXN1]; // vis is cleared in each Dfs
    void Init(int _n1, int _n2)
    {
        n1 = _n1;
        n2 = _n2;
        edges = 0;
        std::fill(last, last + n1, -1);
    }
    void AddEdge(int u, int v)
    {
        head[edges] = v;
        prev[edges] = last[u];
        last[u] = edges++;
    }
    void Bfs()
    {
        std::fill(dist, dist + n1, -1);
        int sizeQ = 0;
        for (int u = 0; u < n1; ++u)
        {
            if (!used[u])
            {
                Q[sizeQ++] = u;
                dist[u] = 0;
            }
        }
        for (int i = 0; i < sizeQ; i++)
        {
            int u1 = Q[i];
            for (int e = last[u1]; e >= 0; e = prev[e])
            {
                int u2 = matching[head[e]];
                if (u2 >= 0 && dist[u2] < 0)
                {
                    dist[u2] = dist[u1] + 1;
                    Q[sizeQ++] = u2;
                }
            }
        }
    }
    bool Dfs(int u1)
    {
        vis[u1] = true;
        for (int e = last[u1]; e >= 0; e = prev[e])
        {
            int v = head[e];
            int u2 = matching[v];
            if (u2 < 0 || (!vis[u2] && dist[u2] == dist[u1] + 1 && Dfs(u2)))
            {
                matching[v] = u1;
                used[u1] = true;
                return true;
            }
        }
        return false;
    }
    int AugmentPath()
    {
        Bfs();
        std::fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && Dfs(u))
                ++f;
        return f;
    }
    int MaxMatching()
    {
        std::fill(used, used + n1, false);
        std::fill(matching, matching + n2, -1);
        for (int res = 0;;)
        {
            int f = AugmentPath();
            if (!f)
                return res;
            res += f;
        }
    }
    std::vector<std::pair<int, int>> GetMatching()
    {
        std::vector<std::pair<int, int>> res;
        for (int i = 0; i < n2; ++i)
            if (matching[i] != -1)
                res.emplace_back(matching[i], i);
        return res;
    }
};
} // namespace library
#endif
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
library::BpmHopcraft<sz, sz, sz> bpm;
void dfs(int u, int p = -1)
{
    for (int v : g[u])
    {
        if (v == p)
            continue;
        d[v] = d[u] ^ 1;
        dfs(v, u);
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
    dfs(1);
    bpm.Init(n + 1, n + 1);
    for (int i = 1; i <= n; i++)
    {
        if (d[i])
        {
            continue;
        }
        for (int v : g[i])
        {
            bpm.AddEdge(i, v);
        }
    }
    printf("%d\n", bpm.MaxMatching());
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
