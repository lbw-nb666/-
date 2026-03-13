/*题目描述
给出一串正整数数列以及一个正整数 C，要求计算出所有满足 A−B=C 的数对的个数（不同位置的数字一样的数对算不同的数对）。

输入格式
输入共两行。

第一行，两个正整数 N,C。

第二行，N 个正整数，作为要求处理的那串数。

输出格式
一行，表示该串正整数中包含的满足 A−B=C 的数对的个数。
*/
#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, C;
    cin >> N >> C;
    vector<long long> nums(N);
    map<long long, long long> freq;
    for (int i = 0; i < N; i++)
    {
        cin >> nums[i];
        freq[nums[i]]++;
    }
    long long count = 0;
    for (int i = 0; i < N; i++)
    {
        long long target = nums[i] + C;
        if (freq.count(target))
        {
            count += freq[target];
        }
    }
    cout << count << endl;
    return 0;
}