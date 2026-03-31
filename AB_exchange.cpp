/*题目描述
小梦有一个长度为 2∗n 的 AB 串 s，即 s 中只包含 "A" 和 "B" 两种字符，且其中恰好有 n 个 "A" 和 n 个 "B"。

他可以对 s 执行以下操作：

∙ 选择 i,j (1≤i,j≤2⋅n,i

=j)，并交换 s
i
​
  和 s
j
​
 。

他想知道，需要至少多少次操作，才能使得 s 满足相邻的字符不相同，请你帮他算一算吧。

输入格式
本题有多组测试数据。

输入的第一行包含一个正整数 T，表示数据组数。

接下来包含 T 组数据，每组数据的格式如下：

第一行一个正整数 n，表示 s 长度的一半。

第二行一个长度为 2∗n 的字符串 s，保证只由 "A", "B" 两种字符构成。

输出格式
对于每组测试数据：

在单独的一行输出一个整数，表示最少进行的操作次数。
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    if (!(cin >> t))
    {
        return 0;
    }

    long long n, num;
    while (t--)
    {
        cin >> n;
        num = 2 * n;
        vector<char> s;
        char ch;
        int ans1 = 0;
        int ans2 = 0;
        while (num--)
        {
            cin >> ch;
            s.push_back(ch);
        }
        bool p1 = false;
        for (long long i = -1; i < 2 * n;)
        {
            while ((!p1) && i < 2 * n)
            {
                i += 2;
                if (s[i] == s[0])
                {
                    p1 = true;
                }
            }
            if (p1)
            {
                p1 = false;
                ++ans1;
            }
        }
        ans2 = n - ans1;
        int ans = ans1 < ans2 ? ans1 : ans2;
        cout << ans << '\n';
    }
}