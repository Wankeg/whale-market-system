#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface/interface.h"

/**
 * @brief 用户登录
 */
make_login(U, SER, checkPass(username, passwd, &curUser));

/**
 * @brief 管理员登录
 */
make_login(A, DMIN,
           strcmp(username, ADMIN_NAME) == 0 &&
               strcmp(passwd, ADMIN_PASS) == 0);

/**
 * @brief 用户注册
 */
static void USER_SignUp() {
  User* u = (User*)malloc(sizeof(User));

  // 输入用户信息
  printf("请输入用户名: ");
  scanf("%s", u->name);
  printf("请输入密码: ");
  scanf("%s", u->passwd);
  printf("请输入联系方式: ");
  scanf("%s", u->contact);
  printf("请输入联系地址: ");
  scanf("%s", u->address);
  u->balance = 0;
  // 添加用户
  if (addUser(u))
    successMessage();
  else
    failureMessage();

  free(u);
}

// 主页面的处理函数列表
static HANDLER handler[] = {USER_Login, USER_SignUp, ADMIN_Login};

// 主页面接口
make_interface(M, AIN);
