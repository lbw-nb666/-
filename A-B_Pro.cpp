/**
 * 题目：洛谷 P1102 A-B 数对
 * 核心公式：A - B = C  =>  A = B + C
 * 最优解法：排序 + C++ STL 双二分查找
 * 时间复杂度：O(N log N)
 * 空间复杂度：O(1) (辅助空间)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 蓝桥杯 A 组/大厂笔试标配：解除输入输出流绑定，极大提升 cin/cout 速度
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long N, C;
    // 边界防御：题目虽然没明说，但遇到连乘或累加，一定要养成开 long long 的习惯
    if (!(cin >> N >> C))
        return 0;

    vector<long long> nums(N);
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
    }

    // 步骤 1：二分查找的绝对前提 —— 排序
    sort(nums.begin(), nums.end());

    long long count = 0; // 记录数对的总个数，极端情况下会超过 int 范围

    // 步骤 2：遍历每一个 B，去有序数组中寻找 A (即 B + C) 的个数
    for (int i = 0; i < N; i++)
    {
        long long target_A = nums[i] + C;

        // 特工 1：找到第一个 >= 目标值的迭代器
        auto it_lower = lower_bound(nums.begin(), nums.end(), target_A);
        // 特工 2：找到第一个 > 目标值的迭代器
        auto it_upper = upper_bound(nums.begin(), nums.end(), target_A);

        // 两个迭代器相减，直接得出目标值在数组中连续出现的个数
        // 如果不存在该目标值，it_upper 会等于 it_lower，相减恰好为 0
        count += (it_upper - it_lower);
    }

    // 蓝桥杯性能规范：大量输出时使用 '\n' 代替 endl，防止频繁刷新缓冲区导致 TLE
    cout << count << "\n";

    return 0;
}