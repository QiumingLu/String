#include <stdio.h>
#include <string.h>

// 在字符串中删除特定的字符
// 输入两个字符串,从第一个字符串中删除第二个字符串中所有的字符

void DeleteChars(char* p_str_source, const char* p_str_delete) {
  if (p_str_source == NULL || p_str_delete == NULL) {
    return;
  }

  const unsigned int table_size = 256;
  bool hashtable[table_size];
  memset(hashtable, false, sizeof(hashtable));
  const char* p_temp = p_str_delete;

  while (*p_temp != '\0') {
    hashtable[*p_temp++] = true;
  }
  char* p_slow = p_str_source;
  char* p_fast = p_str_source;
  while (*p_fast != '\0') {
    if (!hashtable[*p_fast]) {
      *p_slow = *p_fast;
      ++p_slow;
    }
    ++p_fast;
  }
  *p_slow = '\0';
}

int main() {
  char p_str_source[] = "we are the word";
  char p_str_delete[] = "fuck you";
  DeleteChars(p_str_source, p_str_delete);
  printf("%s\n", p_str_source);
  return 0;
}
