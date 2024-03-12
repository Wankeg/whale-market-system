#include "tools/hint.h"

#include <stdio.h>

#include "tools/color.h"

static const char* BANNER_MESSAGE =
    "\
\t__          ___           _          __  __            _        _       _\n\
\t\\ \\        / / |         | |        |  \\/  |          | |      | |     | |\n\
\t \\ \\  /\\  / /| |__   __ _| | ___    | \\  / | __ _ _ __| | _____| |_    | |\n\
\t  \\ \\/  \\/ / | '_ \\ / _` | |/ _ \\   | |\\/| |/ _` | '__| |/ / _ \\ __|   | |\n\
\t   \\  /\\  /  | | | | (_| | |  __/   | |  | | (_| | |  |   <  __/ |_    |_|\n\
\t    \\/  \\/   |_| |_|\\__,_|_|\\___|   |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|   (_)\n\
";
static const char* SUCCESS_MESSAGE = "\t\t*** 操作成功! ***";
static const char* FAILURE_MESSAGE = "\t\t*** 操作失败! ***";
static const char* ILLEGAL_MESSAGE = "\t\t*** 非法输入! ***";
static const char* LOADING_MESSAGE = "\t\t*** 加载中 ... ***";
static const char* EXITING_MESSAGE = "\t\t*** 退出中 ... ***";

void welcomeMessage() {
  setPurpleFront();
  printf("\nWelcome to \n");
  printf("\n%s\n", BANNER_MESSAGE);
  printf("\nThis is WinterCode Project for C-Beginners.\n\n");
  resetFontColor();
}

void successMessage() {
  setGreenFront();
  printf("\n%s\n", SUCCESS_MESSAGE);
  resetFontColor();
}

void failureMessage() {
  setRedFront();
  printf("\n%s\n", FAILURE_MESSAGE);
  resetFontColor();
}

void illegalMessage() {
  setRedFront();
  printf("\n%s\n", ILLEGAL_MESSAGE);
  resetFontColor();
}

void loadingMessage() {
  setBlueFront();
  printf("\n%s\n", LOADING_MESSAGE);
  resetFontColor();
}

void exitingMessage() {
  setWhiteFront();
  printf("\n%s\n", EXITING_MESSAGE);
  resetFontColor();
}

void invalidMessage() {
  setYellowFront();
  printf("\nThis Function is Waiting For you to Implement ...\n");
  resetFontColor();
}
