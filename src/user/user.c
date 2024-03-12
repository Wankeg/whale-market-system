#include "user/user.h"

#include <stdio.h>
#include <string.h>

#include "tools/info.h"

// 所有的用户
static User users[MAX_USER];

// 用户数量
static int totalUser = 0;

// 用户数据存储位置
static const char* filePath = "../data/user.txt";

// 打印头
static const char* header =
    "|\t ID \t|\t 姓名 \t|\t 联系方式 \t|\t 联系地址 \t|\t 余额 \t|\n";

static int searchUserName(const char* name) {
  for (int i = 0; i < totalUser; ++i) {
    if (strcmp(users[i].name, name) == 0) return i;
  }

  return -1;
}

static int searchUserID(const char* id) {
  for (int i = 0; i < totalUser; ++i) {
    if (strcmp(users[i].id, id) == 0) return i;
  }

  return -1;
}

static void printUser(int i) {
  printf("|\t %-10s \t|\t %-10s \t|\t %-10s \t|\t %-10s \t|\t %-10.1f \t|\n",
         users[i].id, users[i].name, users[i].address, users[i].contact,
         users[i].balance);
}

void pullUsers() {
  totalUser = 0;
  FILE* pf = fopen(filePath, "r");

  if (pf) {
    while (fscanf(pf, "%s %s %s %s %s %lf", users[totalUser].id,
                  users[totalUser].name, users[totalUser].passwd,
                  users[totalUser].contact, users[totalUser].address,
                  &(users[totalUser].balance)) != EOF) {
      totalUser++;
    }
    fclose(pf);
  } else {
    printf("加载用户数据文件失败...\n");
    return;
  }
}

void pushUsers() {
  FILE* pf = fopen(filePath, "w");

  if (!pf) {
    printf("加载用户数据文件失败...\n");
    return;
  }
  for (int i = 0; i < totalUser; ++i) {
    fprintf(pf, "%s %s %s %s %s %.1f\n", users[i].id, users[i].name,
            users[i].passwd, users[i].contact, users[i].address,
            users[i].balance);
  }

  fclose(pf);
}

User* getUser(int idx) { return users + idx; }

void userInfo(int i) {
  printf("ID:\t | %s\n", users[i].id);
  printf("姓名:\t | %s\n", users[i].name);
  printf("联系方式:\t | %s\n", users[i].contact);
  printf("联系地址:\t | %s\n", users[i].address);
  printf("余额:\t | %.2f\n", users[i].balance);
}

int addUser(User* u) {
  // 判断用户是否已满
  if (totalUser == MAX_USER) return 0;
  // 查找用户名是否已存在
  if (searchUserName(u->name) != -1) return 0;
  // 生成用户 ID
  generateID(u->id, 'U');
  // 添加用户
  users[totalUser++] = *u;

  // 返回执行结果
  return 1;
}

int deleteUser(const char* id, const char* who) {
  // who 中存放的是行为主体的 ID，只有管理员有权限删除用户（管理员 ID 为 NULL）
  if (who) return 0;
  // 查找用户 ID
  int idx = searchUserID(id);
  // 未查找到用户
  if (idx == -1) return 0;
  // 删除用户
  for (int j = idx; j < totalUser - 1; ++j) {
    users[j] = users[j + 1];
  }
  totalUser--;

  // 返回执行结果
  return 1;
}

void printUsers() {
  print_header;
  for (int i = 0; i < totalUser; ++i) {
    printUser(i);
  }
}

int checkPass(const char* name, const char* passwd, int* idx) {
  *idx = searchUserName(name);
  if (*idx == -1) return 0;

  return strcmp(users[*idx].passwd, passwd) == 0;
}

int userTopUp(const char* id, double m) {
  int idx = searchUserID(id);
  if (idx == -1) return 0;
  users[idx].balance += m;

  return 1;
}
