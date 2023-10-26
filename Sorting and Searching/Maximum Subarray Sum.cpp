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
ll maximum_sub_array_sum(const vector<int> &vec)
{
    ll max_so_far = LONG_LONG_MIN, max_ending_here = 0;
    for (int x : vec)
    {
        max_ending_here = max_ending_here + x;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}
void Solve()
{
    scanf("%d", &n);
    vector<int> a(n);
    for (int &x : a)
        scanf("%d", &x);
    printf("%lld\n", maximum_sub_array_sum(a));
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
