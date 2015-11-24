#include <stdio.h>

struct Node {
  int value;
  Node* next;
  Node() : value(0), next(NULL) { }
  ~Node() { printf("free node\n"); }
};

// 如何在O(1)的时间里删除单链表的节点
void DeleteNode(Node* Linklist, Node* p) {
  printf("delete: %d\n", p->value);
  if (p->next != NULL) {
    p->value = p->next->value;
    Node* tmp = p->next;
    p->next = p->next->next;
    delete(tmp);
  } else {
    Node* tmp = p;
    p = NULL;
    delete tmp;
  }
 /* else if (Linklist == p) {
    delete(p);
  } else {
    node *s = Linklist;
    while(s && s->next != p) {
      s = s->next;
    }
    s->next = s->next->next;
    delete(p);
  }
  */
}

int main() {
  Node* p = new Node();
  p->value = 2;
  p->next = NULL;
  DeleteNode(p, p);
  return 0;
}
