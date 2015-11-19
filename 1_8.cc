// 字符串匹配
// 在一篇英文文章中查找指定的人名, 人名使用二十六个英文字母(可以是大写或小写),
// 空格以及两个通配符组成(*和?),通配符"*"表示零个或多个任意字母,
// 通配符"?"表示一个任意字母.如:"J*Smi??"可以匹配"John Smith".

#include <stdio.h>
#include <iostream>

const char* pEnd = NULL;

bool Match(const char* pszText, const char* pszName) {
  if (*pszName == '\0') {  // 匹配完成
    pEnd = pszText;        // 记录下结束位置
    return true;
  }
  if (*pszText == '\0') {  // 未匹配成功
    while (*pszName != '\0') {
      if(*pszName != '*') {
        return false;
      }
      ++pszName;
    }
    pEnd = pszText;
    return true;
  }
  if (*pszName != '*' && *pszName != '?') {
    if (*pszText == *pszName) {
      return Match(pszText + 1, pszName + 1);
    }
    return false;
  } else {
    if (*pszName == '*') {  
      // 因为*不能匹配空格,所以只能匹配0个字符
      if (*pszText == ' ') {
        return Match(pszText, pszName + 1);
      } else {                      // 匹配0个,或者继续*匹配下去
        return Match(pszText, pszName + 1) || Match(pszText + 1, pszName);
      }
    } else {
      // 因为 ? 不能匹配空格,所以返回 false
      if (*pszText == ' ') {
        return false;
      } 
      return Match(pszText + 1, pszName + 1);
    }
  }
}

void Scan(const char* pszText, const char* pszName) {
  while (*pszText != '\0') {
    if (Match(pszText, pszName)) {
      while (pszText != pEnd) {
        std::cout <<  *pszText;
        ++pszText;
      }
      printf("\n");
    }
    ++pszText;
  }
}

int main() {
  char* pszText = "dsfJohn Smith fffffJo hn Smith";
  char* pszName = "J* Smi??";
  Scan(pszText, pszName);
  return 0;
}
