/*题目描述
为了在上课时保持清醒和专注，Karen 需要喝点咖啡！

Karen 是一位咖啡爱好者，她想知道冲泡完美咖啡的最佳温度。实际上，她花了一些时间阅读了几本食谱，包括备受赞誉的《The Art of the Covfefe》。

她一共掌握了 n 种咖啡配方。第 i 个配方建议咖啡应在 l
i
​
  到 r
i
​
  度（包含端点）之间冲泡，以获得最佳口感。

Karen 认为，如果有至少 k 个配方推荐某个温度，则该温度为可接受温度。

Karen 的想法总是变化多端，于是她总共提出了 q 个问题。每个问题，她都会给定一个温度范围 a 到 b，想让你告诉她，在这个范围内有多少个可接受的整数温度。

输入格式
输入的第一行包含三个整数 n, k（1≤k≤n≤200000）、q（1≤q≤200000），分别表示配方数量、某个温度被判定为可接受所需的最少配方数，以及 Karen 提出的查询个数。

接下来的 n 行描述每个配方。具体地，第 i 行包含两个整数 l
i
​
  和 r
i
​
 （1≤l
i
​
 ≤r
i
​
 ≤200000），表示第 i 个配方推荐咖啡应在 l
i
​
  到 r
i
​
  度（包含端点）之间冲泡。

接下来的 q 行描述各个问题。每行包含两个整数 a 和 b（1≤a≤b≤200000），表示她想知道在 a 到 b（包含端点）度之间有多少个可接受的整数温度。

输出格式
对于每一个问题，输出一行一个整数，表示在 a 到 b 度之间有多少个可接受的整数温度。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n, k, q;
  if (!(cin >> n >> k >> q))
  {
    return 0;
  }
  vector<long long> l(n), r(n);
  for (long long i = 0; i < n; i++)
  {
    cin >> l[i] >> r[i];
  }
  sort(l.begin(), l.end());
  long long left = l[k - 1];
  sort(r.begin(), r.end(), greater<long long>());
  long long right = r[k - 1];
  long long a, b;
  while (q--)
  {
    cin >> a >> b;
    if (a >= left && b <= right)
    {
      cout << b - a + 1 << '\n';
    }
    else
    {
      cout << 0 << '\n';
    }
  }
  return 0;
}