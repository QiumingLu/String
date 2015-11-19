#include <stdio.h>
#include <string.h>

struct Node {
  int data;
  struct Node* next;
};

// 求两个链表的相交节点
Node* FindNode(Node* head1, Node* head2) {
  if (head1 == NULL || head2 == NULL) {
    return NULL;
  }
  Node* p1 = head1, *p2 = head2;
  int len1 = 0, len2 = 0, diff = 0;
  while (p1->next != NULL) {
    ++len1;
    p1 = p1->next;
  }
  while (p2->next != NULL) {
    ++len2;
    p2 = p2->next;
  }
  if (p1 != p2) {
    return NULL;
  }
  diff = abs(len1 - len2);
  if (len1 > len2) {
    p1 = head1;
    p2 = head2;
  } else {
    p1 = head2;
    p2 = head1;
  }

  for (int i = 0; i < diff; ++i) {
    p1 = p1->next;
  }
  while (p1 != p2) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1;
}

