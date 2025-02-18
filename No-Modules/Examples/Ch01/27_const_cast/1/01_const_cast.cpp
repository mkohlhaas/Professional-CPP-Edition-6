void thirdPartyLibraryFunction(char *str [[maybe_unused]]) {
  // ...
}

void f(const char *str) {
  // thirdPartyLibraryFunction(str);
  thirdPartyLibraryFunction(const_cast<char *>(str));
}

int main() {
  f("Hello World");
  // ...
}
