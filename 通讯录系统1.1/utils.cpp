/**
 * @file utils.cpp
 * @brief 工具层函数实现
 */
#include "utils.h"
using namespace std;

int readInt()
{
    int num;
    while(true)
    {
        cin >> num;
        // 判断输入流读取是否失败（输入非数字触发）
        if(cin.fail())
        {
            // 清除cin内部失败状态标记，恢复cin工作能力
            cin.clear();
            // 清空缓冲区残留的垃圾字符，最多读取1024字符，直到遇到换行符
            cin.ignore(1024, '\n');
            cout << "输入不是数字，请重新输入：";
        }
        else
        {
            // 读取成功，返回整数，退出函数
            return num;
        }
    }
}

bool saveJson(const string &filename, const json &j)
{
    // 创建文件输出流
    ofstream ofs(filename);
    if(!ofs.is_open())
    {
        cout << "保存失败，无法打开文件！" << endl;
        return false;
    }
    // dump(4)：格式化输出json，带4空格缩进，方便阅读
    ofs << j.dump(4);
    ofs.close();
    return true;
}

json loadJson(const string &filename)
{
    ifstream ifs(filename);
    if(!ifs.is_open())
    {
        cout << "json文件不存在，使用空通讯录" << endl;
        return json();
    }
    json j;
    try
    {
        // 读取文件内容到json对象
        ifs >> j;
    }
    catch(json::parse_error &e)
    {
        // json格式错误时捕获异常
        cout << "json文件损坏！加载空通讯录" << endl;
        return json();
    }
    ifs.close();
    return j;
}
