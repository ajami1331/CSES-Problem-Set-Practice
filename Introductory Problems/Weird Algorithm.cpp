
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
void rec(ll x)
{
    printf("%lld", x);
    if (x == 1)
    {
        printf("\n");
        return;
    }
    printf(" ");
    if (x & 1)
    {
        rec(x * 3 + 1);
        return;
    }
    rec(x / 2);
}
void Solve()
{
    scanf("%d", &n);
    rec(n);
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
