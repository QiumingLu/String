// 字符个数的统计
// char* str = "AbcBca", 写出一个函数,查找出每个字符的个数,
// 区分大小写,要求时间复杂度是n(提示用ASCII)
#include <stdio.h>
#include <string.h>

void CharNumber(char* str) {
  const unsigned int size = 256;
  int char_number[size];
  memset(char_number, 0, sizeof(char_number));
  while (*str != '\0') {
    ++char_number[*str++];
  }
  for (unsigned i = 0; i < size; ++i) {
    if (char_number[i] > 0) {
      printf("%c %d\n", i, char_number[i]);
    }
  }
}

int main() {
  char str[] = "abbsbdnaaak";
  CharNumber(str);
  return 0;
}
