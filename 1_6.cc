// 两个单链表
// 找出两个链表的第一个公共结点
template <typename T>
struct ListNode {
  T data;
  ListNode* next;
};

template <typename T>
int GetListLength(ListNode<T>* head) {
  int length = 0;
  while(head) {
    ++length;
    head = head->next;
  }
  return length;
}

template <typename T>
ListNode<T>* FindFirstCommonNode(ListNode<T>* head1, ListNode<T>* head2) {
  int length1 = GetListLength(head1);
  int length2 = GetListLength(head2);

  if (length1 < length2) {
    ListNode<T> temp = head1;
    head1 = head2;
    head2 = temp;
  }
  
  for (int i = 0; i < length1 - length2; ++i) {
    head1 = head1->next;
  }

  while (head1 && head1 != head2) {
    head1 = head1->next;
    head2 = head2->next;
  }
  
  return head1;
}

