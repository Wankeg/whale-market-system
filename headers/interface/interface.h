#ifndef INTERFACE_H
#define INTERFACE_H

#include "config.h"
#include "good/good.h"
#include "menu/menu.h"
#include "order/order.h"
#include "tools/hint.h"
#include "user/user.h"

/**
 * 界面通过相应的菜单获取用户输入并进行处理
 */

// 菜单加载和处理的通用宏
#define make_interface(T, YPE)        \
  void T##YPE##_Interface() {         \
    successMessage();                 \
    int op = menu(T##YPE);            \
    while (op != optionNum[T##YPE]) { \
      loadingMessage();               \
      handler[op - 1]();              \
      op = menu(T##YPE);              \
    }                                 \
    loadingMessage();                 \
    successMessage();                 \
  }

// 获取用户名和密码的通用宏
#define get_username_passwd \
  char username[MAX_LEN];   \
  char passwd[MAX_LEN];     \
  printf("用户名: ");       \
  scanf("%s", username);    \
  printf("密码: ");         \
  scanf("%s", passwd);

// 登录的通用宏
#define make_login(T, YPE, cond) \
  static void T##YPE##_Login() { \
    get_username_passwd;         \
    if (cond) {                  \
      T##YPE##_Interface();      \
      return;                    \
    }                            \
    failureMessage();            \
  }

// 打印所有信息的通用宏
#define make_all(T, YPE)         \
  static void all##T##YPE##s() { \
    print##T##YPE##s();          \
    successMessage();            \
  }

// 删除数据的通用宏
#define make_ban(T, YPE, Name, Who)         \
  static void ban##T##YPE() {               \
    char id[MAX_LEN];                       \
    printf("请输入要删除 %s 的ID: ", Name); \
    scanf("%s", id);                        \
    if (delete##T##YPE(id, Who))            \
      successMessage();                     \
    else                                    \
      failureMessage();                     \
  }

// 搜索商品的通用宏
#define make_search(WHO)                \
  static void search() {                \
    char buffer[MAX_LEN];               \
    printf("请输入要搜索的商品名称: "); \
    scanf("%s", buffer);                \
    loadingMessage();                   \
    searchGoodNameFor##WHO(buffer);     \
    successMessage();                   \
  }

// 将字符串转为双精度数字和检测非法输入的通用宏
#define check_double       \
  double m = atof(buffer); \
  while (1) {              \
    if (m > 0) break;      \
    illegalMessage();      \
    printf("请重试: ");    \
    scanf("%s", buffer);   \
    m = atof(buffer);      \
  }

// 修改信息的通用宏
#define make_modify(TYPE, W, HO)       \
  static void modify_##TYPE() {        \
    char buffer[MAX_LEN];              \
    printf("请输入新的 %s: ", #TYPE);  \
    scanf("%s", buffer);               \
    W##HO* x = get##W##HO(cur##W##HO); \
    strcpy(x->TYPE, buffer);           \
    successMessage();                  \
  }

// 为指定用户打印信息的通用宏
#define make_my(TYPE, W, HO)                       \
  static void my##TYPE() {                         \
    print##TYPE##For##W##HO(getUser(curUser)->id); \
    successMessage();                              \
  }

// 处理函数的函数指针
typedef void (*HANDLER)(void);

// 当前用户
extern int curUser;

// 当前商品
extern int curGood;

/**
 * @brief 主菜单
 *
 * 1）用户登录
 * 2）用户注册
 * 3）管理员登录
 * 4）退出
 */
void MAIN_Interface();

/**
 * @brief 管理员菜单
 *
 * 1）所有商品
 * 2）搜索商品
 * 3）查看订单
 * 4）所有用户
 * 5）删除用户
 * 6）下架商品
 * 7）返回
 */
void ADMIN_Interface();

/**
 * @brief 用户菜单
 *
 * 1）买家
 * 2）卖家
 * 3）个人信息
 * 4）返回
 */
void USER_Interface();

/**
 * @brief 买家菜单
 *
 * 1）查看商品
 * 2）购买商品
 * 3）搜索商品
 * 4）查看订单
 * 5）查看商品信息
 * 6）返回
 */
void BUYER_Interface();

/**
 * @brief 卖家菜单
 *
 * 1）出售商品
 * 2）我的商品
 * 3）修改商品信息
 * 4）下架商品
 * 5）查看订单
 * 6）返回
 */
void SELLER_Interface();

/**
 * @brief 个人信息菜单
 *
 * 1）我的信息
 * 2）修改个人信息
 * 3）充值
 * 4）返回
 */
void INFO_Interface();

/**
 * @brief 修改个人信息菜单
 *
 * 1）修改密码
 * 2）修改联系方式
 * 3）修改地址
 * 4）返回
 */
void MODIFY_Interface();

/**
 * @brief 修改商品信息菜单
 *
 * 1）修改名称
 * 2）修改价格
 * 3）修改描述
 * 4）返回
 */
void GOOD_Interface();

#endif  // INTERFACE_H
