#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interface/interface.h"

int curGood = -1;

/**
 * @brief 修改商品名
 */
make_modify(name, G, ood);

/**
 * @brief 修改商品描述
 */
make_modify(description, G, ood);

/**
 * @brief 修改商品价格
 */
static void modify_price() {
  char buffer[MAX_LEN];
  printf("请输入新的价格: ");
  scanf("%s", buffer);
  check_double;
  Good* g = getGood(curGood);
  g->price = m;
  successMessage();
}

// 商品页面的处理函数列表
static HANDLER handler[] = {modify_name, modify_price, modify_description};

// 商品页面的接口
make_interface(G, OOD);
