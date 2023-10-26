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
    if (n  == 2 || n == 3) {
        printf("NO SOLUTION\n");
        return;
    }
    for (int i = 2; i <= n; i += 2) {
        printf("%d ", i);
    }
    for (int i = 1; i <= n; i += 2) {
        printf("%d ", i);
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
