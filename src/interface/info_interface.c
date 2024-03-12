#include <stdio.h>
#include <stdlib.h>

#include "interface/interface.h"

/**
 * @brief 打印用户详细信息
 */
static void info() {
  userInfo(curUser);
  successMessage();
}

/**
 * @brief 用户充值
 */
static void topUp() {
  char buffer[MAX_LEN];
  printf("请输入要充值的金额: ");
  scanf("%s", buffer);
  check_double;
  // 更新用户信息
  User* u = getUser(curUser);
  u->balance += m;
  successMessage();
}

// 信息页面的处理函数列表
static HANDLER handler[] = {info, MODIFY_Interface, topUp};

// 信息页面接口
make_interface(I, NFO);
