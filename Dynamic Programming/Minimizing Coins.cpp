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
const int sz = 1e6 + 105;
int n, m, k;
int t;
int coins[105];
int dp[sz];
void Solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", coins + i);
    }
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
    {
        dp[i] = sz;
        for (int j = 0; j < n; j++)
        {
            if (i >= coins[j])
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    printf("%d\n", dp[m] == sz ? -1 : dp[m]);
}
} // namespace solution
#endif // solution_h
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
