#include <stdio.h>

void next_char(int pos, char *ns, char *s, int n) {
  if (pos == n) {
    printf("%s\n", ns);
    return;
  }
  char bitArray[n];
  for (int i = 0; i < n; i++) {
    bitArray[i] = 0;
  }
  for (int j = 0; j < pos; j++) {
    for (int i = 0; i < n; i++) {
      if (ns[j] == s[i] && bitArray[i] != 1) {
        bitArray[i] = 1;
        break;
      }
    }
  }
  for (int i = 0; i <= (n - pos); i++) {
    for (int j = 0; j < n; j++) {
      if (bitArray[j] != 1) {
        for (int k = j + 1; k < n; k++) {
          if (s[k] == s[j]) {
            bitArray[k] = 1;
          }
        }
        bitArray[j] = 1;
        ns[pos] = s[j];
        next_char(pos + 1, ns, s, n);
      }
    }
  }
}

int main(void) {
  char word[] = "programming";
  char newWord[12];
  newWord[11] = '\0';
  next_char(0, &newWord[0], &word[0], 11);
  return 0;
}