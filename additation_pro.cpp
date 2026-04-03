#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 极速 I/O
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    if (!(cin >> n))
        return 0;

    // 🌟 核心技巧 1：数组大小开到 n + 1，下标从 1 开始使用
    // 原数组 a 和前缀和数组 prefix
    vector<long long> a(n + 1, 0);
    vector<long long> prefix(n + 1, 0);

    // 1. 录入数据并【同时】计算前缀和
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        // 🌟 核心技巧 2：当前的前缀和 = 前一个前缀和 + 当前数字
        prefix[i] = prefix[i - 1] + a[i];
    }

    int m;
    cin >> m;

    // 2. O(1) 极速查询
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        // 🌟 核心技巧 3：区间 [l, r] 的和 = prefix[r] - prefix[l - 1]
        // 这里没有任何 for 循环！不管区间多大，永远只做一次减法！
        cout << prefix[r] - prefix[l - 1] << '\n';
    }

    return 0;
}