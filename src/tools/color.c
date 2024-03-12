#include "tools/color.h"

#include <Windows.h>

void resetFontColor() {
  // 恢复默认字体颜色
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void setBlackFront() {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0);
}

void setWhiteFront() {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE |
                              FOREGROUND_INTENSITY);
}

void setRedFront() {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          FOREGROUND_RED | FOREGROUND_INTENSITY);
}

void setGreenFront() {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void setYellowFront() {
  SetConsoleTextAttribute(
      GetStdHandle(STD_OUTPUT_HANDLE),
      FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
}

void setBlueFront() {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                          FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}

void setPurpleFront() {
  SetConsoleTextAttribute(
      GetStdHandle(STD_OUTPUT_HANDLE),
      FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
