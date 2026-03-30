/**
 * 洛谷 P5250 【木材仓库】
 * 核心考点：STL set 的动态维护与 lower_bound 边界处理
 */
#include <iostream>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<long long> woods; // 只存长度，用 set 最合适
    int m;
    if (!(cin >> m))
        return 0;

    while (m--)
    {
        int op;
        long long length;
        cin >> op >> length;

        if (op == 1)
        { // 进货
            // set 的 insert 会返回一个 pair，它的 second 表示是否插入成功
            // 如果本来就有，插入就会失败。这比先 find 再 insert 更快！
            auto result = woods.insert(length);
            if (!result.second)
            {
                cout << "Already Exist\n";
            }
        }
        else if (op == 2)
        { // 出货
            if (woods.empty())
            {
                cout << "Empty\n";
                continue;
            }

            // 🌟 必须使用 set 专属的 lower_bound！
            // 找到第一个 >= length 的木材迭代器
            auto right = woods.lower_bound(length);

            // 情况 A：刚好找到了长度一模一样的
            if (right != woods.end() && *right == length)
            {
                cout << *right << '\n';
                woods.erase(right);
            }
            // 情况 B：没找到一样的，要找最接近的
            else
            {
                if (right == woods.begin())
                {
                    // 目标比仓库里所有木材都小，只能拿最小的 (也就是 right 指向的第一个)
                    cout << *right << '\n';
                    woods.erase(right);
                }
                else if (right == woods.end())
                {
                    // 目标比仓库里所有木材都大，只能拿最大的 (也就是 right 前面那一个)
                    auto left = right;
                    --left; // 迭代器往前退一格
                    cout << *left << '\n';
                    woods.erase(left);
                }
                else
                {
                    // 目标卡在中间，我们需要比较 right 和 left(前一个) 谁更接近
                    auto left = right;
                    --left;

                    long long diff_left = length - *left;
                    long long diff_right = *right - length;

                    // 题目要求：如果距离一样，取比较短的一根 (也就是 left)
                    if (diff_left <= diff_right)
                    {
                        cout << *left << '\n';
                        woods.erase(left);
                    }
                    else
                    {
                        cout << *right << '\n';
                        woods.erase(right);
                    }
                }
            }
        }
    }
    return 0;
}