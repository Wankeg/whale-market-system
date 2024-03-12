#include <stdio.h>
#include <string.h>

#include "interface/interface.h"

/**
 * @brief 修改密码
 */
static void modify_passwd() {
  char buffer[MAX_LEN];
  User* u = getUser(curUser);

  printf("请输入当前密码: ");
  scanf("%s", buffer);
  // 验证密码是否正确，不正确则停止修改
  if (strcmp(u->passwd, buffer)) {
    failureMessage();
    return;
  }
  printf("请输入新密码: ");
  scanf("%s", buffer);
  strcpy(u->passwd, buffer);
  successMessage();
}

/**
 * @brief 修改联系方式
 */
make_modify(contact, U, ser);

/**
 * @brief 修改地址
 */
make_modify(address, U, ser);

// 修改页面的处理函数列表
static HANDLER handler[] = {modify_passwd, modify_contact, modify_address};

// 修改页面接口
make_interface(M, ODIFY);
