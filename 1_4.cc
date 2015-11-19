#include <stdio.h>

// 单链表逆序输出
void PrintSList(slist* pList) {
  if(pList == NULL) {
    return;
  }
  if (pList->next == NULL) {
    printf("%s\n", *pList);
  } else {
    PrintSList(pList->next);
    printf("%s\n", *pList);
  }
}
