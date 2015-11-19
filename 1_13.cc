// 找出最长的重复子串
// 一个长度为10000的字符串,写一个算法,找出最长的重复子串,如abczzacbca,
// 结果是bc (思路:后缀树/数组的典型应用,@well: 就是求后缀数组的height[]
// 的最大值)
// 第一种O(n^2)的复杂度
// 第二种用后缀数组

#include <string.h>
#include <stdio.h>

#define  BUF_MAX 10000
int maxi;     // 子串起始位置
int maxlen;   // 子串的长度
void StrSearch(const char* str) {
  int len, k, p, q;
  maxlen = -1;
  len = strlen(str);
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      p = i, q = j;
      k = 0;
      while (str[p] && str[p] == str[q]) {
        ++p;
        ++q;
        ++k;
      }
      if (k > maxlen) {
        maxlen = k;
        maxi = i;
      }
    }
  }
}

int main() {
  char str[BUF_MAX];
  scanf("%s", str);
  StrSearch(str);
  for (int i = maxi; i < maxi + maxlen; ++i) {
    printf("%c", str[i]);
  }
  printf("\n");
  return 0;
}
