#ifndef INFO_H_
#define INFO_H_

// 打印头信息宏定义
#define print_header printf("%s\n", header);

/**
 * 生成各类 ID 和获取时间模块
 */

/**
 * 生成一个给定类型 ID
 *
 * @param {dest}	存储 ID 的目标字符串
 * @param {dest}	ID 类型，U-用户，G-商品，O-订单
 */
void generateID(char* dest, char type);

/**
 * 获取当前日期
 *
 * @param {dest}	存储日期的目标字符串
 */
void getDate(char* dest);

#endif  // !INFO_H_
