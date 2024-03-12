#include "good/good.h"

#include <stdio.h>
#include <string.h>

#include "tools/info.h"

// 所有商品
static Good goods[MAX_GOOD];

// 商品数量
static int totalGood = 0;

// 商品数据存储位置
static const char* filePath = "../data/good.txt";

// 商品状态类型列表
static const char* stateName[] = {"Selling", "Sold", "Banned"};

// 打印头
static const char* header =
    "|\t ID \t|\t 名称 \t|\t 价格 \t|\t 日期 \t|\t 卖家 \t|\t 状态 \t|";

void pullGoods() {
  totalGood = 0;
  FILE* pf = fopen(filePath, "r");

  if (pf) {
    while (fscanf(pf, "%s %s %lf %s %u %s %s", goods[totalGood].id,
                  goods[totalGood].name, &goods[totalGood].price,
                  goods[totalGood].seller_id, &goods[totalGood].state,
                  goods[totalGood].date, goods[totalGood].description) != EOF) {
      totalGood++;
    }
    fclose(pf);
  } else {
    printf("商品数据文件加载失败...\n");
    return;
  }
}

void pushGoods() {
  FILE* pf = fopen(filePath, "w");

  if (!pf) {
    printf("商品数据文件加载失败...\n");
    return;
  }
  for (int i = 0; i < totalGood; ++i) {
    fprintf(pf, "%s %s %.1f %s %u %s %s\n", goods[i].id, goods[i].name,
            goods[i].price, goods[i].seller_id, goods[i].state, goods[i].date,
            goods[i].description);
  }

  fclose(pf);
}

Good* getGood(int idx) { return goods + idx; }

int addGood(Good* good) {
  // 商品已满
  if (totalGood == MAX_GOOD) return 0;
  // 设置商品信息
  generateID(good->id, 'G');
  getDate(good->date);
  good->state = SELLING;
  goods[totalGood++] = *good;

  // 执行成功
  return 1;
}

int searchGoodById(const char* id) {
  for (int i = 0; i < totalGood; ++i) {
    if (strcmp(goods[i].id, id) == 0) return i;
  }

  return -1;
}

int deleteGood(const char* id, const char* who) {
  // 查找商品下标
  int idx = searchGoodById(id);
  // 如果为 -1，表示不存在
  if (idx == -1) return 0;
  // 判断操作权限
  if (who && strcmp(goods[idx].seller_id, who)) return 0;
  // 下架商品
  goods[idx].state = BANNED;

  // 删除成功
  return 1;
}

void goodInfo(int i) {
  printf("ID:\t | %s\n", goods[i].id);
  printf("名称:\t | %s\n", goods[i].name);
  printf("描述:\t | %s\n", goods[i].description);
  printf("日期:\t | %s\n", goods[i].date);
  printf("价格:\t | %.1f\n", goods[i].price);
  printf("卖家:\t | %s\n", goods[i].seller_id);
  printf("状态:\t | %s\n", stateName[goods[i].state]);
}

void printGood(int i) {
  printf(
      "|\t %-10s \t|\t %-10s \t|\t %-10.1f \t|\t %-10s \t|\t %-10s \t|\t %-10s "
      "\t|\n",
      goods[i].id, goods[i].name, goods[i].price, goods[i].date,
      goods[i].seller_id, stateName[goods[i].state]);
}

void printGoods() {
  print_header;
  for (int i = 0; i < totalGood; ++i) {
    printGood(i);
  }
}

void searchGoodNameForBuyer(const char* name) {
  print_header;
  for (int i = 0; i < totalGood; ++i) {
    if (goods[i].state == SELLING && strstr(goods[i].name, name)) {
      printGood(i);
    }
  }
}

void searchGoodNameForAdmin(const char* name) {
  print_header;
  for (int i = 0; i < totalGood; ++i) {
    if (strstr(goods[i].name, name)) {
      printGood(i);
    }
  }
}

void printGoodsForSeller(const char* id) {
  print_header;
  for (int i = 0; i < totalGood; ++i) {
    if (strcmp(goods[i].seller_id, id) == 0) {
      printGood(i);
    }
  }
}

void printGoodsForBuyer(const char* id) {
  print_header;
  for (int i = 0; i < totalGood; ++i) {
    if (goods[i].state == SELLING) {
      printGood(i);
    }
  }
}
