/**
 * @file logic.cpp
 * @brief 逻辑层业务函数实现，通讯录增删改查核心逻辑
 */
#include "logic.h"
#include <iostream>
#include "utils.h"
using namespace std;

void addPerson(personbook *book)
{
    // 判断通讯录容量是否已满
    if(book->size == Max)
    {
        cout << "通讯录已满！" << endl;
        return;
    }
    person p;
    cout << "请输入姓名:";
    cin >> p.name;

    cout << "请输入年龄:";
    p.age = readInt();

    // 循环校验性别只能输入1或2
    while(true)
    {
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        cout << "请输入性别:";
        p.gender = readInt();
        if(p.gender ==1 || p.gender ==2)
        {
            break;
        }
        cout << "输入错误，请重新输入：" << endl;
    }

    cout << "请输入电话号码:";
    cin >> p.phone;
    cout << "请输入住址:";
    cin >> p.adress;

    // 将新联系人存入数组，人数+1
    book->PerArray[book->size] = p;
    book->size++;
    cout << "添加成功" << endl;
}

int isExist(personbook *book, const string &name)
{
    // 遍历数组比对姓名
    for(int i = 0; i < book->size; i++)
    {
        if(book->PerArray[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

void delPerson(personbook *book)
{
    string name;
    cout << "请输入你想要删除的联系人姓名：";
    cin >> name;
    int ret = isExist(book, name);
    if(ret == -1)
    {
        cout << "没有查到这个人" << endl;
        return;
    }
    // 删除逻辑：后面元素向前覆盖
    for(int i = ret; i < book->size - 1; i++)
    {
        book->PerArray[i] = book->PerArray[i+1];
    }
    book->size--;
    cout << "删除成功" << endl;
}

void modifyPerson(personbook *book)
{
    string name;
    cout << "请输入你要修改的联系人姓名：";
    cin >> name;
    int ret = isExist(book, name);
    if(ret == -1)
    {
        cout << "没有找到该联系人" << endl;
        return;
    }
    // 引用，简化书写，直接修改原联系人
    person &p = book->PerArray[ret];
    cout << "请输入新姓名:";
    cin >> p.name;
    cout << "请输入新年龄:";
    p.age = readInt();
    while(true)
    {
        cout << "1---男" << endl;
        cout << "2---女" << endl;
        cout << "请输入性别:";
        p.gender = readInt();
        if(p.gender ==1 || p.gender ==2) break;
        cout << "输入错误，请重新输入：" << endl;
    }
    cout << "请输入新电话:";
    cin >> p.phone;
    cout << "请输入新住址:";
    cin >> p.adress;
    cout << "修改完成" << endl;
}

void clearPerson(personbook *book)
{
    // 逻辑清空：只把人数置0，数组原有数据保留，后续会覆盖
    book->size = 0;
    cout << "通讯录已清空" << endl;
}

json bookToJson(const personbook &book)
{
    json j;
    j["size"] = book.size;
    json arr = json::array();
    for(int i=0;i<book.size;i++)
    {
        json p;
        p["name"] = book.PerArray[i].name;
        p["age"] = book.PerArray[i].age;
        p["gender"] = book.PerArray[i].gender;
        p["phone"] = book.PerArray[i].phone;
        p["adress"] = book.PerArray[i].adress;
        arr.push_back(p);
    }
    j["persons"] = arr;
    return j;
}

void bookFromJson(const json &j, personbook &book)
{
    book.size = 0;
    if(!j.contains("size")) return;
    book.size = j["size"];
    auto arr = j["persons"];
    for(int i = 0; i < book.size; i++)
    {
        book.PerArray[i].name = arr[i]["name"];
        book.PerArray[i].age = arr[i]["age"];
        book.PerArray[i].gender = arr[i]["gender"];
        book.PerArray[i].phone = arr[i]["phone"];
        book.PerArray[i].adress = arr[i]["adress"];
    }
}
