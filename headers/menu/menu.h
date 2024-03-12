#ifndef MENU_H
#define MENU_H

/**
 * @brief 菜单类型枚举
 */
typedef enum {
  // 主菜单
  MAIN,
  // 管理员菜单
  ADMIN,
  // 用户菜单
  USER,
  // 买家菜单
  BUYER,
  // 卖家菜单
  SELLER,
  // 个人信息菜单
  INFO,
  // 修改信息菜单
  MODIFY,
  // 商品菜单
  GOOD
} Menu;

/**
 * @brief 打印提示信息
 *
 * @param type 菜单类型
 */
static void promptMessage(Menu type);

// 不同菜单的选项数目
extern const int optionNum[];

/**
 * @brief 菜单的作用是给出提示信息并获取用户输入
 *
 * @param type 菜单类型
 * @return 用户的有效输入
 */
int menu(Menu type);

#endif  // MENU_H
