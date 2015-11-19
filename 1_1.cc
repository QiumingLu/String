#include <stdio.h>
#include <string.h>

// 返回第一次出现的字符
char FirstOnceChar(char* str) {
  if (str == NULL) {
    return '\0';
  }
  int hashtable[256];
  memset(hashtable, 0, sizeof(hashtable));
  char* pCur = str;
  while(*pCur != '\0') {
    if (*pCur >= 0) {
      hashtable[*(pCur++)]++;
    } else {
      hashtable[*(pCur++) + 256]++;
    }
  }
  while(*str != '\0') {
    int index;
    if(*str >= 0) {
      index = *str;
    } else {
      index = *str + 256;
    }
    if (hashtable[index] == 1) {
      return *str;
    } else {
      str++;
    }
  }
  return '\0';
}

// 返回第一个出现一次的字符的下标
int IndexOfFirstOnceChar(char* str) {
  if (str == NULL) {
    return -1;
  } 
  int len = strlen(str);
  int hashtable[256];
  memset(hashtable, 0, sizeof(hashtable));
  for (int i = 0; i < len; ++i) {
    if (str[i] >= 0) {
      hashtable[str[i]]++;
    } else {
      hashtable[str[i] + 256]++;
    }
  }

  for (int i = 0; i < len; ++i) {
    int index;
    if (str[i] >= 0) {
      index = str[i];
    } else {
      index = str[i] + 256;
    }
    if (hashtable[index] == 1) {
      return i;
    }
  }
  return -1;
}

int main() {
  char *str = "ABACCDEFF";
  char res = FirstOnceChar(str); 
  int i = IndexOfFirstOnceChar(str);
  printf("%c %d\n",res, i);
  return 0;
}
