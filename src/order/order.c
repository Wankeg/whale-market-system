#include "order/order.h"

#include <stdio.h>
#include <string.h>

#include "tools/info.h"

// 订单列表
static Order orders[MAX_ORDER];

// 订单数量
static int totalOrder = 0;

// 数据存储位置
static const char* filePath = "../data/order.txt";

// 打印头
static const char* header =
    "|\t ID \t|\t 商品 \t|\t 价格 \t|\t 日期 \t|\t 卖家 \t|\t 买家 \t|";

static void printOrder(int i) {
  printf(
      "|\t %-10s \t|\t %-10s \t|\t %-10.1f \t|\t %-10s \t|\t %-10s \t|\t %-10s "
      "\t|",
      orders[i].id, orders[i].good_id, orders[i].price, orders[i].date,
      orders[i].seller_id, orders[i].buyer_id);
}

void pullOrders() {
  totalOrder = 0;
  FILE* pf = fopen(filePath, "r");

  if (pf) {
    while (fscanf(pf, "%s %s %lf %s %s %s", orders[totalOrder].id,
                  orders[totalOrder].good_id, &orders[totalOrder].price,
                  orders[totalOrder].date, orders[totalOrder].seller_id,
                  orders[totalOrder].buyer_id) != EOF) {
      totalOrder++;
    }
  } else {
    printf("订单数据文件加载失败...\n");
    return;
  }

  fclose(pf);
}

void pushOrders() {
  FILE* pf = fopen(filePath, "w");

  if (!pf) {
    printf("订单数据文件加载失败...\n");
    return;
  }
  for (int i = 0; i < totalOrder; ++i) {
    fprintf(pf, "%s %s %.1f %s %s %s\n", orders[i].id, orders[i].good_id,
            orders[i].price, orders[i].date, orders[i].seller_id,
            orders[i].buyer_id);
  }

  fclose(pf);
}

int addOrder(Order* order) {
  if (totalOrder == MAX_ORDER) return 0;
  // 生成订单信息
  generateID(order->id, 'O');
  getDate(order->date);
  // 添加订单
  orders[totalOrder++] = *order;

  return 1;
}

void printOrders() {
  print_header;
  for (int i = 0; i < totalOrder; ++i) {
    printOrder(i);
  }
}

void printOrdersForSeller(const char* id) {
  print_header;
  for (int i = 0; i < totalOrder; ++i) {
    if (strcmp(orders[i].seller_id, id) == 0) printOrder(i);
  }
}

void printOrdersForBuyer(const char* id) {
  print_header;
  for (int i = 0; i < totalOrder; ++i) {
    if (strcmp(orders[i].buyer_id, id) == 0) printOrder(i);
  }
}
