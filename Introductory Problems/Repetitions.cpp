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
string s;
void Solve()
{
    cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int j = i;
        for (j = i; j < s.size(); j++)
        {
            if (s[i] != s[j])
            {
                break;
            }
            ans = max(ans, j - i + 1);
        }
        i = j - 1;
    }
    printf("%d\n", ans);
}
} // namespace solution
#endif
#define _CRT_SECURE_NO_WARNINGS
int main()
{
    solution::Solve();
    return 0;
}