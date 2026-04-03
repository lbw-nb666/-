/*题目背景
这次不是数列的问题了。

题目描述
给定一个 n 行 m 列的矩阵 a，有 q 次询问，每次给定 (u,v) 和 (x,y)，请你求出：

(
i=u
∑
x
​

j=v
∑
y
​
 a
i,j
​
 )mod2
64

也就是求出以 (u,v) 为左上角、(x,y) 为右下角的矩形元素和对 2
64
  取余数的结果。

输入格式
本题单测试点内有多组测试数据。

输入的第一行是一个整数 T，表示数据组数。接下来依次给出每组数据的输入信息：

第一行三个整数，依次表示矩阵的行数 n 和列数 m 以及询问数 q。
接下来 n 行，每行 m 个整数。第 i 行第 j 个整数表示 a
i,j
​
 。
接下来 q 行，每行四个整数，依次为 u,v,x,y，表示一组询问。

输出格式
为了避免输出过大，对于每组数据，请输出一行一个整数，表示本组数据的所有询问的答案的按位异或和。
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, n, m;
    unsigned long long q, num;
    int u, v, x, y;
    if (!(cin >> t))
    {
        return 0;
    }
    while (t--)
    {
        if (!(cin >> n >> m >> q))
            return 0;
        vector<vector<unsigned long long>> matrix(n + 1, vector<unsigned long long>(m + 1, 0));
        vector<vector<unsigned long long>> prematr(n + 1, vector<unsigned long long>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> matrix[i][j];
                prematr[i][j] = prematr[i - 1][j] + matrix[i][j];
            }
        }

        unsigned long long ans = 0;
        while (q--)
        {
            if (!(cin >> u >> v >> x >> y))
                return 0;
            unsigned long long num = 0;
            for (int i = v; i <= y; i++)
            {
                num += prematr[x][i] - prematr[u - 1][i];
            }
            ans ^= num;
        }
        cout << ans << '\n';
    }
}