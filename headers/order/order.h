#ifndef ORDER_H
#define ORDER_H

#include "config.h"

/**
 * 订单类型定义
 */
typedef struct {
  char id[MAX_LEN];
  char good_id[MAX_LEN];
  double price;
  char date[MAX_LEN];
  char seller_id[MAX_LEN];
  char buyer_id[MAX_LEN];
} Order;

/**
 * @brief 打印单个订单
 *
 * @param i 订单下标
 */
static void printOrder(int i);

/**
 * @brief 从文件导入订单数据
 */
void pullOrders();

/**
 * @brief 订单数据导出到文件
 */
void pushOrders();

/**
 * @brief 新增订单
 *
 * @param order 订单
 * @return 添加成功为 1，失败为 0
 */
int addOrder(Order* order);

/**
 * @brief 打印所有订单
 */
void printOrders();

/**
 * @brief 为卖家打印订单
 * @param id 卖家 id
 */
void printOrdersForSeller(const char* id);

/**
 * @brief 为买家打印订单
 * @param id 买家 id
 */
void printOrdersForBuyer(const char* id);

#endif  // ORDER_H
