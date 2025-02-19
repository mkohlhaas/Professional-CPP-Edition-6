#include <cstring>
#include <print>

using namespace std;

int main() {
  char text1[]{"abcdef"};
  size_t s1{sizeof(text1)}; // 7
  size_t s2{strlen(text1)}; // 6
  println("{}\n{}", s1, s2);

  const char *text2{"abcdef"};
  size_t s3{sizeof(text2)}; // 8 (pointer size)
  size_t s4{strlen(text2)}; // 6
  println("{}\n{}", s3, s4);
}
