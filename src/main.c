#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#include "interface/interface.h"
#include "tools/hint.h"

int main(int argc, char* argv[]) {
  system("chcp 65001");

  // 加载数据
  pullUsers();
  pullGoods();
  pullOrders();

  // 程序开始
  welcomeMessage();
  MAIN_Interface();
  exitingMessage();

  // 保留数据
  pushUsers();
  pushGoods();
  pushOrders();

  return 0;
}
