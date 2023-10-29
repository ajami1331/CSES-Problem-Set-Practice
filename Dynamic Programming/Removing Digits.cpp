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
int dp[sz];
vector <int> digits(int x)
{
    vector <int> ret;
    while (x > 0)
    {
        ret.emplace_back(x % 10);
        x /= 10;
    }
    return ret;
}
void Solve()
{
    scanf("%d", &n);
    dp[0] = 0;
    fill(dp + 1, dp + n + 1, sz + sz);
    for (int i = 0; i <= n; i++)
    {
        for (int j: digits(i))
        {
            if (i >= j)
            {
                dp[i] = min(dp[i], dp[i - j] + 1);
            }
        }
    }
    printf("%d\n", dp[n]);
}
} // namespace solution
#endif // solution_h
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
