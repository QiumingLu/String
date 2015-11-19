#include <stdio.h>
#include <string.h>
// 对称字符串的最长长度

// 判断起始指针为pBegin, 结束指针为pEnd的字符串是否对称
bool IsSymmetrical(char* pBegin, char* pEnd) {
  if (pBegin == NULL || pEnd == NULL || pBegin > pEnd) {
    return false;
  }
  while (pBegin < pEnd) {
    if (*pBegin != *pEnd) {
      return false;
    }
    ++pBegin;
    --pEnd;
  }
  return true;
}

// 取出所有对称字串的最大长度
// 时间复杂度 O(n^3)
int GetLongestSymmetricalLength_1(char* pString) {
  if (pString == NULL) {
    return 0;
  } 
  int symmetricalLength = 1;
  char* pFirst = pString;
  int length = strlen(pString);

  while (pFirst < &pString[length - 1]) {
    char* pLast = pFirst + 1;
    while (pLast <= &pString[length - 1]) {
      if (IsSymmetrical(pFirst, pLast)) {
        int newLength = pLast - pFirst + 1;
        if (newLength > symmetricalLength) {
          symmetricalLength = newLength;
        }
      }
      pLast++;
    }
    pFirst++;
  }
  return symmetricalLength;
}

// 取出所有对称子串的最大长度
// 时间复杂度: O(n ^ 2)
int GetLongestSymmetricalLength_2(char* pString) {
  if (pString == NULL) {
    return 0;
  }
  int symmetricalLength = 1;
  char* pChar = pString;
  while (*pChar != '\0') {
    char* left = pChar - 1;
    char* right = pChar + 1;
    while (left >= pString && *right != '\0' && *left == *right) {
      --left;
      ++right;
    }
    int newLength = right - left - 1;
    if (newLength > symmetricalLength) {
      symmetricalLength = newLength;
    }

    left = pChar;
    right = pChar + 1;
    while(left >= pString && right != '\0' && *left == *right) {
      --left;
      ++right;
    }
    newLength = right - left - 1;
    if (newLength > symmetricalLength) {
      symmetricalLength = newLength;
    }
    pChar++;
  }
  return symmetricalLength;
}

int main() {
  char p[] = "google";
  int res_1 = GetLongestSymmetricalLength_1(p);
  int res_2 = GetLongestSymmetricalLength_2(p);
  printf("%d %d\n", res_1, res_2);
  return 0;
}
