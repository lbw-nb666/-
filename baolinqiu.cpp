/*
输入格式
第一行包含一个正整数 n，表示位置数。

第二行包含 n 个正整数 a
i
​
  ，表示第 i 个位置的瓶子数，保证各个位置的瓶子数不同。

第三行包含一个正整数 Q，表示 DL 发球的次数。

第四行至文件末尾，每行包含一个正整数 m，表示 DL 需要打倒 m 个瓶子。

输出格式
共 Q 行。每行包含一个整数，第 i 行的整数表示 DL 第 i 次的发球位置。若无解，则输出 0。
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long N, num;
  cin >> N;
  map<long long, long long> a;
  for (long long i = 0; i < N; i++)
  {
    cin >> num;
    a[num] = i + 1;
  }
  long long Q;
  cin >> Q;
  for (long long i = 0; i < Q; i++)
  {
    long long m;
    cin >> m;
    cout << a[m] << endl;
  }
  return 0;
}