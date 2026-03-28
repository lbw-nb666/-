/**
 * 题目：洛谷 P5266 【深基17.例6】学籍管理
 * 核心考点：STL map 的高阶查询与插入机制
 * 优化级别：极致（去除冗余树搜索，优化 I/O 缓冲区）
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    // 1. 蓝桥杯标配极速 I/O
    ios::sync_with_stdio(false);
    cin.tie(0);

    map<string, long long> stu;
    int Q;
    if (!(cin >> Q))
        return 0;

    while (Q--)
    {
        int op;
        cin >> op;
        string name;
        long long score;

        // 在竞赛中，面对简单的数值分支，用 if-else if 往往比 switch 结构更紧凑
        if (op == 1)
        {
            cin >> name >> score;
            // 🌟 终极优化：[] 运算符天生自带“无则新建，有则覆盖”的底层机制！
            // 不需要任何 if-else，一行代码直接搞定插入和更新。
            stu[name] = score;
            cout << "OK\n"; // 🚨 严禁用 endl，一律换成 '\n'
        }
        else if (op == 2)
        {
            cin >> name;
            // 🌟 终极优化：只爬一次红黑树！获取迭代器
            auto it = stu.find(name);
            if (it != stu.end())
            {
                // 直接顺着迭代器的物理地址去读成绩，这是绝对的 O(1) 极速读取
                cout << it->second << '\n';
            }
            else
            {
                cout << "Not found\n";
            }
        }
        else if (op == 3)
        {
            cin >> name;
            auto it = stu.find(name);
            if (it != stu.end())
            {
                // 🌟 终极优化：直接将迭代器交给 erase()。
                // 这比 erase(name) 速度更快，因为它省去了内部再次查找 name 的时间。
                stu.erase(it);
                cout << "Deleted successfully\n";
            }
            else
            {
                cout << "Not found\n";
            }
        }
        else if (op == 4)
        {
            // size() 在 C++11 之后是 O(1) 的复杂度，放心调用
            cout << stu.size() << '\n';
        }
    }

    return 0;
}