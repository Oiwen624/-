/**
 * @file main.cpp
 * @brief 程序入口文件
 * @details 主循环，负责调度显示层、逻辑层；程序启动加载JSON，退出保存JSON
 */
#include <iostream>
#include "view.h"
#include "logic.h"
#include "utils.h"
using namespace std;

int main()
{
    // 创建通讯录对象
    personbook book;
    book.size = 0;
    // 程序启动，读取本地json，加载历史联系人数据
    json j = loadJson("addr.json");
    bookFromJson(j, book);

    int select;
    // 主循环，程序持续运行直到选择0退出
    while(true)
    {
        showMenu();
        select = readInt();
        switch (select)
        {
            case 1:
                addPerson(&book);
                waitContinue();
                break;
            case 2:
                showAllPerson(&book);
                waitContinue();
                break;
            case 3:
                delPerson(&book);
                waitContinue();
                break;
            case 4:
                showOnePerson(&book);
                waitContinue();
                break;
            case 5:
                modifyPerson(&book);
                waitContinue();
                break;
            case 6:
                clearPerson(&book);
                waitContinue();
                break;
            case 0:
            {
                // 退出前保存数据到json文件
                json out = bookToJson(book);
                saveJson("addr.json", out);
                cout << "退出通讯录，数据已保存" << endl;
                return 0;
            }
            default:
                cout << "输入错误，请重新选择！" << endl;
                waitContinue();
                break;
        }
    }
    return 0;
}
