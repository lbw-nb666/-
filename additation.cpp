/*题目描述
给定 n 个正整数组成的数列 a
1
​
 ,a
2
​
 ,⋯,a
n
​
  和 m 个区间 [l
i
​
 ,r
i
​
 ]，分别求这 m 个区间的区间和。

输入格式
第一行包含一个正整数 n，表示序列的长度。

第二行包含 n 个正整数 a
1
​
 ,a
2
​
 ,⋯,a
n
​
 。

第三行包含一个正整数 m，表示区间的数量。

接下来 m 行，每行包含两个正整数 l
i
​
 ,r
i
​
 ，满足 1≤l
i
​
 ≤r
i
​
 ≤n。

输出格式
共 m 行，其中第 i 行包含一个正整数，表示第 i 组答案的询问。
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, m, num, l, r;
    vector<long long> nums;
    if (!(cin >> n))
    {
        return 0;
    }
    nums.reserve(n);
    while (n--)
    {
        cin >> num;
        nums.push_back(num);
    }

    if (!(cin >> m))
    {
        return 0;
    }

    while (m--)
    {
        long long ans = 0;
        cin >> l >> r;
        for (long long i = l - 1; i <= r - 1; ++i)
        {
            ans += nums[i];
        }
        cout << ans << '\n';
    }
    return 0;
}