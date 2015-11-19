// 后缀数组求最长重复子串
// 输入一个字符串,如何求最大重复出现的字符串呢?
// 给定一个字符串，求出其最长的重复子串。

// 分析：使用后缀数组，对一个字符串生成相应的后缀数组后，然后再排序，
// 排完序依次检测相邻的两个字符串的开头公共部分。 这样的时间复杂度为：

// 生成后缀数组 O(N)
// 排序 O(NlogN*N) 最后面的 N 是因为字符串比较也是 O(N)
// 依次检测相邻的两个字符串 O(N * N)
// 故最终总的时间复杂度是 O(N^2*logN)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXCHAR 1000 

char c[MAXCHAR], *a[MAXCHAR];

int Comlen(char* p, char* q) {
  int i = 0;
  while (*p && (*p++ == *q++)) {
    ++i;
  }
  return i;
}

int PStrCmp(const void* p1, const void* p2) {
  return strcmp(*(char* const *)p1, *(char* const *)p2);
}

int main() {
  char ch;
  int n = 0;
  int i, temp;
  int maxlen = 0, maxi = 0;

  while ((ch = getchar()) != '\n') {
    a[n] = &c[n];
    c[n++] = ch;
  }
  c[n] = '\0';
  qsort(a, n, sizeof(char*), PStrCmp);
  
  for (i = 0; i < n - 1; ++i) {
    temp = Comlen(a[i], a[i + 1]);
    if (temp > maxlen) {
      maxlen = temp;
      maxi = i;
    }
  }

  printf("%.*s\n", maxlen, a[maxi]);
  return 0;
}
