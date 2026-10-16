#ifndef VIEW_H
#define VIEW_H
/**
 * @file view.h
 * @brief 显示层头文件，UI界面模块
 * @details 负责控制台打印、表格展示、暂停等待、清屏。只做展示，不修改通讯录业务数据
 */
#include "logic.h"

/**
 * @brief 打印主菜单界面
 */
void showMenu();

/**
 * @brief 打印通讯录全部联系人表格
 * @param book 通讯录指针
 */
void showAllPerson(personbook *book);

/**
 * @brief 根据姓名查询单个联系人并展示
 * @param book 通讯录指针
 */
void showOnePerson(personbook *book);

/**
 * @brief 等待按回车继续，之后清屏（Mac）
 */
void waitContinue();

#endif
