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
void Solve()
{
    scanf("%d", &n);
    vector<int> a(n);
    for (int &x : a)
        scanf("%d", &x);
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    printf("%d\n", (int)a.size());
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}
