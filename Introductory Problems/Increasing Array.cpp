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
int n;
void Solve()
{
    scanf("%d", &n);
    vector<int> a(n);
    for (int &x : a) scanf("%d", &x);
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ans += max(0, a[i - 1] - a[i]);
        a[i] += max(0, a[i - 1] - a[i]);
    }
    printf("%lld\n", ans);
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
