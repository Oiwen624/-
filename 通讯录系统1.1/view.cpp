/**
 * @file view.cpp
 * @brief 显示层UI实现，负责控制台界面输出
 */
#include "view.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "utils.h"
using namespace std;

void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

void showAllPerson(personbook *book)
{
    if(book->size == 0)
    {
        cout << "当前通讯录人数为0" << endl;
        return;
    }
    cout << "当前通讯录人数：" << book->size << endl;
    cout << left; // 设置输出左对齐，配合setw格式化表格
    for(int i = 0; i < book->size; i++)
    {
        cout
        <<"姓名 "<<setw(8)<<book->PerArray[i].name
        <<"年龄 "<<setw(4)<<book->PerArray[i].age
        <<"性别 "<<setw(4)<<(book->PerArray[i].gender==1? "男" : "女")
        <<"电话 "<<setw(13)<<book->PerArray[i].phone
        <<"地址 "<<book->PerArray[i].adress
        <<endl;
    }
}

void showOnePerson(personbook *book)
{
    string name;
    cout << "请输入你要查找的人：";
    cin >> name;
    int ret = isExist(book,name);
    if(ret == -1)
    {
        cout << "没有找到该联系人" << endl;
        return;
    }
    cout << left;
    cout
    <<"姓名 "<<setw(8)<<book->PerArray[ret].name
    <<"年龄 "<<setw(4)<<book->PerArray[ret].age
    <<"性别 "<<setw(4)<<(book->PerArray[ret].gender==1? "男" : "女")
    <<"电话 "<<setw(13)<<book->PerArray[ret].phone
    <<"地址 "<<book->PerArray[ret].adress
    <<endl;
}

void waitContinue()
{
    cout << "按回车键继续..." << endl;
    cin.ignore(1024, '\n');
    cin.get();
    system("clear"); // Mac终端清屏命令
}
