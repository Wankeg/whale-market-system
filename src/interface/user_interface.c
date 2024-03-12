#include "interface/interface.h"

// 当前用户
int curUser = -1;

// 用户界面的处理函数列表
static HANDLER handler[] = {BUYER_Interface, SELLER_Interface, INFO_Interface};

// 用户界面接口
make_interface(U, SER)
