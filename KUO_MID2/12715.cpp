#include <cstdio>
#include <cstring>
#include "12715.h"
#include "12715main.cpp"
using namespace oj;

int main() {
  //freopen("output.txt", "w", stdout);
  static char s[1024];

  int T;
  std::scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    BigInt B(s);

    int Q;
    std::scanf("%d", &Q);

    while (Q--) {
      char op[5];
      scanf("%s", op);
      if (!strcmp(op, "++B")) std::printf("%s\n", (++B).to_s());
      if (!strcmp(op, "B++")) std::printf("%s\n", (B++).to_s());
      if (!strcmp(op, "--B")) std::printf("%s\n", (--B).to_s());
      if (!strcmp(op, "B--")) std::printf("%s\n", (B--).to_s());
    }
  }

  return 0;
}
