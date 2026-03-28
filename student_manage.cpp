/*您要设计一个学籍管理系统，最开始学籍数据是空的，然后该系统能够支持下面的操作（不超过 10
5
  条）：

插入与修改，格式 1 NAME SCORE：在系统中插入姓名为 NAME(由字母和数字组成不超过 20 个字符的字符串，区分大小写)，分数为 SCORE（0<SCORE<2
31
 ） 的学生。如果已经有同名的学生则更新这名学生的成绩为 SCORE。如果成功插入或者修改则输出 OK。
查询，格式 2 NAME：在系统中查询姓名为 NAME 的学生的成绩。如果没能找到这名学生则输出 Not found，否则输出该生成绩。
删除，格式 3 NAME：在系统中删除姓名为 NAME 的学生信息。如果没能找到这名学生则输出 Not found，否则输出 Deleted successfully。
汇总，格式 4：输出系统中学生数量。
输入格式
第一行，输入一个正整数 Q（1≤Q≤10
5
 ），表示操作数量。

接下来 Q 行，每行先输入一个正整数 op（op∈[1,4]），表示操作种类。接着：

如果 op=1，则再输入一个字符串 NAME 以及一个正整数 SCORE，含义见题目描述。
如果 op=2，则再输入一个字符串 NAME，含义见题目描述。
如果 op=3，则再输入一个字符串 NAME，含义见题目描述。
如果 op=4，则无需再输入其他内容。
输出格式
共输出 Q 行，每行输出一个字符串或正整数，为对应操作的处理结果，具体含义见题目描述。

输入输出样例
*/
#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    map<string, long long> stu;
    long long Q;
    cin >> Q;
    int op;
    string name;
    long long score;
    while (Q--)
    {
        cin >> op;
        switch (op)
        {
        case 1:
            cin >> name >> score;
            if (stu.count(name))
            {
                stu[name] = score;
            }
            else
            {
                stu.insert({name, score});
            }
            cout << "OK" << endl;
            break;
        case 2:
            cin >> name;
            if (stu.count(name))
            {
                cout << stu[name] << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        case 3:
            cin >> name;
            if (stu.count(name))
            {
                stu.erase(name);
                cout << "Deleted successfully" << endl;
            }
            else
            {
                cout << "Not found" << endl;
            }
            break;
        case 4:
            cout << stu.size() << endl;
            break;
        }
    }
    return 0;
}