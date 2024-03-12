#include "tools/info.h"

#include <stdio.h>
#include <time.h>

// 当前 ID 的最大值记录文件
static const char* filePath = "../data/id.txt";

void generateID(char* dest, char type) {
  int uid = 0, gid = 0, oid = 0;

  // 读取 ID 最大值记录
  FILE* pf = fopen(filePath, "r");
  if (!pf) {
    printf("加载ID数据文件失败...\n");
    return;
  }
  fscanf(pf, "%d %d %d", &uid, &gid, &oid);
  fclose(pf);
  // 生成 ID
  int id = 0;
  switch (type) {
    case 'U':
      id = uid++;
      break;
    case 'G':
      id = gid++;
      break;
    case 'O':
      id = oid++;
      break;
  }
  sprintf(dest, "%c%05d", type, id);
  // 记录 ID 最大值
  pf = fopen(filePath, "w");
  if (!pf) {
    printf("加载ID数据文件失败...\n");
    return;
  }
  fprintf(pf, "%d %d %d\n", uid, gid, oid);
  fclose(pf);
}

void getDate(char* dest) {
  time_t rawtime;
  time(&rawtime);
  struct tm* timeinfo = localtime(&rawtime);
  sprintf(dest, "%d-%d-%d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1,
          timeinfo->tm_mday);
}
