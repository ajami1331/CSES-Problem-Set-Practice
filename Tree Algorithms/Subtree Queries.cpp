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
#ifndef FenwickTree_h
#define FenwickTree_h 1
#include <cstring>
#include <functional>
#include <numeric>
namespace library
{
#define LOG2(x) (32 - __builtin_clz(x) - 1)
template <typename T, size_t sz, typename op_combine_type = std::plus<T>, typename op_decombine_type = std::minus<T>,
          typename less_type = std::less<T>>
class FenwickTree
{
  private:
    T tr[sz];
    int LOGN = LOG2(sz);
    op_combine_type op_combine;
    op_decombine_type op_decombine;
    less_type less;
  public:
    FenwickTree()
    {
        Reset();
    }
    void Reset()
    {
        memset(tr, 0, sizeof tr);
    }
    void Update(size_t x, T v)
    {
        for (; x < sz; x += (x & -x))
        {
            tr[x] = op_combine(tr[x], v);
        }
    }
    T Query(size_t x)
    {
        T ret = 0;
        for (; x > 0; x -= (x & -x))
        {
            ret = op_combine(ret, tr[x]);
        }
        return ret;
    }
    T QueryRange(size_t l, size_t r)
    {
        return op_decombine(Query(r), Query(l - 1));
    }
    void RangeUpdate(size_t l, size_t r, T v)
    {
        Update(l, v);
        Update(r + 1, op_decombine(0, v));
    }
    size_t BinarySearch(T v)
    {
        T sum = 0;
        size_t pos = 0;
        for (int i = LOGN; i >= 0; i--)
        {
            if (pos + (1 << i) >= sz)
                continue;
            T newSum = op_combine(sum, tr[pos + (1 << i)]);
            if (less(newSum, v))
            {
                sum = newSum;
                pos += (1 << i);
            }
        }
        return pos + 1;
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
int ar[sz];
vector<int> graph[sz];
int start[sz], finish[sz];
int tim;
library::FenwickTree<ll, sz> ft;
void dfs(int u, int p = -1)
{
    start[u] = ++tim;
    for (auto v : graph[u])
    {
        if (v == p)
        {
            continue;
        }
        dfs(v, u);
    }
    finish[u] = tim;
}
void Solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", ar + i);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
    {
        ft.Update(start[i], ar[i]);
    }
    while (m--)
    {
        int type, x, y;
        scanf("%d", &type);
        if (type == 1)
        {
            scanf("%d %d", &x, &y);
            ft.Update(start[x], -ar[x]);
            ar[x] = y;
            ft.Update(start[x], ar[x]);
        }
        else
        {
            scanf("%d", &x);
            printf("%lld\n", ft.QueryRange(start[x], finish[x]));
        }
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
