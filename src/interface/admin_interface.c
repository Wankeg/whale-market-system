#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface/interface.h"

/**
 * @brief 打印所有用户
 */
make_all(U, ser);

/**
 * @brief 打印所有商品
 */
make_all(G, ood);

/**
 * @brief 打印所有订单
 */
make_all(O, rder);

/**
 * @brief 删除用户
 */
make_ban(U, ser, "User", NULL);

/**
 * @brief 删除商品
 */
make_ban(G, ood, "Good", NULL);

/**
 * @brief 管理员搜索商品
 */
make_search(Admin);

// 管理员页面的处理函数列表
static HANDLER handler[] = {allGoods, search,  allOrders,
                            allUsers, banUser, banGood};
// 管理员页面接口
make_interface(A, DMIN);
