// 如何在O(1)的时间里删除单链表的节点
void DeleteNode(node* Linklist, node* p) {
  printf("delete: %d\n", p->val);
  if (p->next != NULL) {
    p->val = p->next->val;
    node* tmp = p->next;
    p->next = p->next->next;
    delete(tmp);
  } else if (Linklist == p) {
    delete(p);
  } else {
    node *s = Linklist;
    while(s && s->next != p) {
      s = s->next;
    }
    s->next = s->next->next;
    delete(p);
  }
}
