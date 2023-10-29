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
const int sz = 1e5 + 105;
int n, m, k;
int t;
int page[1005];
int price[1005];
int dp[sz];
void Solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", price + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", page + i);
    }
    fill(dp, dp + sz, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            if (j - price[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
            }
        }
    }
    printf("%d\n", *max_element(dp, dp + sz));
}
} // namespace solution
#endif // solution_h
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
