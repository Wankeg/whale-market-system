#ifndef USER_H
#define USER_H

#include "config.h"

/**
 * @brief 用户类型定义
 */
typedef struct {
  // 用户 id
  char id[MAX_LEN];
  // 名称
  char name[MAX_LEN];
  // 密码
  char passwd[MAX_LEN];
  // 联系方式
  char contact[MAX_LEN];
  // 地址
  char address[MAX_LEN];
  // 余额
  double balance;
} User;

/**
 * @brief 根据用户名查找用户
 *
 * @param name 待查找的用户名
 * @return 查找成功返回数组下标，失败返回 -1
 */
static int searchUserName(const char* name);

/**
 * @brief 查找给定 ID 的用户
 *
 * @param id 用户 id
 * @return 成功返回下标，失败返回 -1
 */
static int searchUserID(const char* id);

/**
 * @brief 打印单个用户作为表格的一行
 *
 * @param 用户下标
 */
static void printUser(int i);

/**
 * @brief 从外部文件导入用户信息
 */
void pullUsers();

/**
 * @brief 将用户信息导出到外部文件
 */
void pushUsers();

/**
 * @brief 获取用户对象
 *
 * @param idx 用户的数组下标
 * @return 指向对应用户的指针
 */
User* getUser(int idx);

/**
 * @brief 打印详细的用户信息
 *
 * @param i 用户的数组下标
 */
void userInfo(int i);

/**
 * @brief 添加新用户
 *
 * @param u 待添加的用户指针
 * @return 添加成功返回 1，失败返回 0
 */
int addUser(User* u);

/**
 * @brief 删除给定 ID 的用户
 *
 * @param id 待删除用户的 id
 * @param who 删除操作执行者的 id，管理员为 null
 * @return 删除成功返回 1，失败返回 0
 */
int deleteUser(const char* id, const char* who);

/**
 * @brief 打印所有用户的信息
 */
void printUsers();

/**
 * @brief 检查用户名和密码是否匹配
 *
 * @param name 用户名
 * @param passwd 密码
 * @param idx 如果成功，通过指针返回用户的下标
 * @return  匹配成功返回 1，失败返回 0
 */
int checkPass(const char* name, const char* passwd, int* idx);

/**
 * @brief 用户充值
 *
 * @param id 待充值用户 id
 * @param m 充值数额
 * @return 充值成功返回 1，失败返回 0
 */
int userTopUp(const char* id, double m);

#endif  // USER_H
