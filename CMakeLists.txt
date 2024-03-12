cmake_minimum_required(VERSION 3.5)

project(whale_market_system_window LANGUAGES C)

# 包含进目录
include_directories(${PROJECT_SOURCE_DIR}/headers)
include_directories(${PROJECT_SOURCE_DIR}/src)

# 主程序文件
set(MAIN_SOURCES
    "src/main.c"
)

# 工具类文件
set(UTILS_SOURCE
    "headers/tools/color.h"
    "src/tools/color.c"
    "headers/tools/hint.h"
    "src/tools/hint.c"
    "headers/tools/info.h"
    "src/tools/info.c"
)

# 配置类文件
set(CONFIG_SOURCE
    "headers/config.h"
)

# 用户类文件
set(USER_SOURCE
    "headers/user/user.h"
    "src/user/user.c"
)

# 订单类文件
set(ORDER_SOURCE
    "headers/order/order.h"
    "src/order/order.c"
)

# 商品类文件
set(GOOD_SOURCE
    "headers/good/good.h"
    "src/good/good.c"
)

# 菜单类文件
set(MENU_SOURCE
    "headers/menu/menu.h"
    "src/menu/menu.c"
)

# 统一接口类文件
set(INTERFACE_SOURCE
    "headers/interface/interface.h"
    "src/interface/main_interface.c"
    "src/interface/admin_interface.c"
    "src/interface/user_interface.c"
    "src/interface/info_interface.c"
    "src/interface/modify_interface.c"
    "src/interface/seller_interface.c"
    "src/interface/good_interface.c"
    "src/interface/buyer_interface.c"
)

# 创建层级结构
# source_group("Main Source Files" FILES ${MAIN_SOURCES})
# source_group("Utils Source Files" FILES ${UTILS_SOURCE})
# source_group("Config Source Files" FILES ${CONFIG_SOURCE})
# source_group("User Source Files" FILES ${USER_SOURCE})
# source_group("Order Source Files" FILES ${ORDER_SOURCE})
# source_group("Good Source Files" FILES ${GOOD_SOURCE})
# source_group("Menu Source Files" FILES ${MENU_SOURCE})
# source_group("Interface Source Files" FILES ${INTERFACE_SOURCE})

# 将源代码添加到此项目的可执行文件
add_executable(
    whale_market_system_window
    ${MAIN_SOURCES}
    ${UTILS_SOURCE}
    ${CONFIG_SOURCE}
    ${USER_SOURCE}
    ${ORDER_SOURCE}
    ${GOOD_SOURCE}
    ${MENU_SOURCE}
    ${INTERFACE_SOURCE}
 )

include(GNUInstallDirs)

install(TARGETS whale_market_system_window
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
