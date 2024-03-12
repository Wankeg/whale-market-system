#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface/interface.h"

/**
 * @brief 购买商品
 */
static void buy() {
  char buffer[MAX_LEN];
  printf("请输入要购买商品ID: ");
  scanf("%s", buffer);
  int idx = searchGoodById(buffer);

  Good* g = getGood(idx);
  User* u = getUser(curUser);
  // 如果商品是不正在售卖状态和商品价格大于买家余额，则购买失败
  if (g->state != SELLING || g->price > u->balance) {
    failureMessage();
    return;
  }
  // 成功购买商品
  u->balance -= g->price;
  g->state = SOLD;
  userTopUp(g->seller_id, g->price);
  // 生成订单
  Order* o = (Order*)malloc(sizeof(Order));
  strcpy(o->good_id, g->id);
  strcpy(o->seller_id, g->seller_id);
  strcpy(o->buyer_id, u->id);
  o->price = g->price;
  // 添加订单
  if (addOrder(o))
    successMessage();
  else
    failureMessage();

  free(o);
}

/**
 * @brief 查看商品信息
 */
static void info() {
  char buffer[MAX_LEN];
  printf("请输入要查看商品ID: ");
  scanf("%s", buffer);
  int idx = searchGoodById(buffer);
  if (idx == -1) {
    failureMessage();
    return;
  }
  loadingMessage();
  goodInfo(idx);
  successMessage();
}

/**
 * 买家搜索商品
 */
make_search(Buyer);

/**
 * @brief 查看买家商品
 */
make_my(Goods, B, uyer);

/**
 * @brief 查看买家订单
 */
make_my(Orders, B, uyer);

// 买家页面的处理函数列表
static HANDLER handler[] = {myGoods, buy, search, myOrders, info};

// 买家页面接口
make_interface(B, UYER);
