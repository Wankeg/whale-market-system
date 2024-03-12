#ifndef GOOD_H
#define GOOD_H

#include "config.h"

/**
 * @brief 商品状态枚举
 */
typedef enum {
  // 销售中
  SELLING,
  // 已售出
  SOLD,
  // 已下架
  BANNED
} State;

/**
 * @brief 商品类型定义
 */
typedef struct {
  // 商品 id
  char id[MAX_LEN];
  // 商品名称
  char name[MAX_LEN];
  // 价格
  double price;
  // 卖家
  char seller_id[MAX_LEN];
  // 商品状态
  State state;
  // 日期
  char date[MAX_LEN];
  // 商品描述
  char description[MAX_LEN];
} Good;

/**
 * @brief 从外部文件导入商品信息
 */
void pullGoods();

/**
 * @brief 将商品信息导出到外部文件
 */
void pushGoods();

/**
 * @brief 获取商品对象
 *
 * @param idx 商品在数组的下标
 * @return 指向对应商品的指针
 */
Good* getGood(int idx);

/**
 * @brief 添加新商品
 *
 * @param good 待添加的商品
 * @return 添加成功返回 1，失败 0
 */
int addGood(Good* good);

/**
 * @brief 查找指定 ID 的商品
 *
 * @param id 商品 ID
 * @return 成功返回下标，失败返回 -1
 */
int searchGoodById(const char* id);

/**
 * @brief 删除给定 ID 的商品
 *
 * @param id 商品 ID
 * @param who 删除操作者 id，管理员为 null
 * @return 删除成功返回 1，失败 0
 */
int deleteGood(const char* id, const char* who);

/**
 * @brief 打印详细的商品信息
 *
 * @param i 商品的数组下标
 */
void goodInfo(int i);

/**
 * @brief 打印所有商品的信息
 *
 * @param i 商品的数组下标
 */
void printGood(int i);

/**
 * @brief 打印所有商品
 */
void printGoods();

/**
 * @brief 为买家搜索商品 - 只搜索正在出售中的商品
 *
 * @param name 待搜索商品的名称
 */
void searchGoodNameForBuyer(const char* name);

/**
 * @brief 为管理员搜索商品 - 搜索所有商品
 *
 * @param name 待搜索商品的名称
 */
void searchGoodNameForAdmin(const char* name);

/**
 * @brief 打印给定卖家 id 的商品
 *
 * @param id 需要打印商品的卖家 id
 */
void printGoodsForSeller(const char* id);

/**
 * @brief 打印给定买家 id 的商品
 *
 * @param id 需要打印商品的买家 id
 */
void printGoodsForBuyer(const char* id);

#endif  // GOOD_H
