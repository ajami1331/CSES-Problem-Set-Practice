#ifndef DEBUG_H
#define DEBUG_H 1
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#ifndef CLown1331
#define debug(...) 0
#define ASSERT(...) 0
#define dbg(...) 0
#endif
#endif // DEBUG_H
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
string s[1005];
bool vis[1005][1005];
void dfs(int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m || vis[x][y] || s[x][y] == '#')
    {
        return;
    }
    vis[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}
void Solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; ++j)
        {
            if (s[i][j] == '.' && !vis[i][j])
            {
                dfs(i, j);
                ++ans;
            }
        }
    }
    printf("%d\n", ans);
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
