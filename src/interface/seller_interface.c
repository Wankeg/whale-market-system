#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface/interface.h"

/**
 * @brief 添加销售商品
 */
static void sell() {
  User* seller = getUser(curUser);
  Good* good = (Good*)malloc(sizeof(Good));

  printf("请输入商品信息 ... \n");
  printf("名称: ");
  scanf("%s", good->name);
  printf("价格: ");
  char buffer[MAX_LEN];
  scanf("%s", buffer);
  check_double;
  good->price = m;
  printf("描述: ");
  scanf("%s", good->description);
  strcpy(good->seller_id, seller->id);
  if (addGood(good))
    successMessage();
  else
    failureMessage();

  free(good);
}

/**
 * @brief 修改商品信息
 */
static void modify() {
  printf("请输入要修改的商品ID: ");
  char buffer[MAX_LEN];
  scanf("%s", buffer);
  curGood = searchGoodById(buffer);
  if (curGood == -1) {
    failureMessage();
    return;
  }
  User* u = getUser(curUser);
  Good* g = getGood(curGood);
  if (strcmp(u->id, g->seller_id) == 0 && g->state == SELLING)
    GOOD_Interface();
  else
    failureMessage();
}

/**
 * @brief 查看卖家商品
 */
make_my(Goods, S, eller);

/**
 * @brief 查看卖家订单
 */
make_my(Orders, S, eller);

/**
 * @brief make_ban
 */
make_ban(G, ood, "Good", getUser(curUser)->id);

// 卖家页面的处理函数列表
static HANDLER handler[] = {sell, myGoods, modify, banGood, myOrders};

// 卖家页面接口
make_interface(S, ELLER);
