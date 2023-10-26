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
    vector<int> a(n - 1);
    for (auto &x : a)
        scanf("%d", &x);
    sort(a.begin(), a.end());
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 != a[i])
        {
            ans = i + 1;
            break;
        }
    }
    printf("%d\n", ans == -1 ? n + 1 : ans);
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
