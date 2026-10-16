#ifndef LOGIC_H
#define LOGIC_H
/**
 * @file logic.h
 * @brief 逻辑层头文件，通讯录核心业务模块
 * @details 定义联系人、通讯录结构体；声明增删改查、JSON序列化业务函数
 *          只负责数据管理，不负责界面打印，不处理清屏暂停
 */
#include <string>
#include "json.hpp"
using json = nlohmann::json;

// 通讯录最大存储联系人数量
const int Max = 1000;

/**
 * @struct person
 * @brief 联系人结构体，保存单个联系人信息
 */
struct person
{
    std::string name;    // 姓名
    int age;             // 年龄
    int gender;          // 性别：1-男，2-女
    std::string phone;   // 电话号码
    std::string adress;  // 住址
};

/**
 * @struct personbook
 * @brief 通讯录结构体，管理全部联系人数组与当前人数
 */
struct personbook
{
    struct person PerArray[Max]; // 联系人数组
    int size;                    // 当前通讯录有效联系人数量
};

/**
 * @brief 添加联系人
 * @param book 通讯录结构体指针
 */
void addPerson(personbook *book);

/**
 * @brief 查找联系人（按姓名查找）
 * @param book 通讯录指针
 * @param name 待查找姓名
 * @return int 找到返回数组下标；未找到返回 -1
 */
int isExist(personbook *book, const std::string &name);

/**
 * @brief 删除联系人
 * @param book 通讯录结构体指针
 */
void delPerson(personbook *book);

/**
 * @brief 修改联系人信息
 * @param book 通讯录结构体指针
 */
void modifyPerson(personbook *book);

/**
 * @brief 清空通讯录所有联系人
 * @param book 通讯录结构体指针
 */
void clearPerson(personbook *book);

/**
 * @brief 通讯录结构体转为json对象（序列化：内存数据→json）
 * @param book 通讯录常量引用
 * @return json 序列化后的json对象
 */
json bookToJson(const personbook &book);

/**
 * @brief json对象转为通讯录结构体（反序列化：json→内存数据）
 * @param j 源json对象
 * @param book 输出通讯录结构体
 */
void bookFromJson(const json &j, personbook &book);

#endif
