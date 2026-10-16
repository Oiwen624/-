#ifndef UTILS_H
#define UTILS_H
/**
 * @file utils.h
 * @brief 工具层头文件，存放项目通用工具函数，与通讯录业务解耦
 * @details 包含安全整数输入、JSON文件读写功能，可复用在其他C++控制台项目
 */
#include <iostream>
#include <string>
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

/**
 * @brief 安全读取整数函数
 * @return int 合法的整数
 * @details 如果用户输入字母/符号，自动清空输入流错误标记与缓冲区，循环提示重新输入
 */
int readInt();

/**
 * @brief 将json对象保存到本地文件
 * @param filename 保存的文件名
 * @param j 待写入的json对象
 * @return bool 成功返回true，文件打开失败返回false
 */
bool saveJson(const std::string &filename, const json &j);

/**
 * @brief 从本地文件读取json数据
 * @param filename 读取的文件名
 * @return json 读取得到的json对象；文件不存在/损坏则返回空json
 */
json loadJson(const std::string &filename);

#endif
