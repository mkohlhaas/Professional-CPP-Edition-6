#include <cstddef>
#include <print>

using std::println;

int
main ()
{
  int i1{ -7 };
  println ("{}", i1);

  signed int i2{ -6 };
  println ("{}", i2);

  signed i3{ -5 };
  println ("{}", i3);

  short s1{ 13 };
  println ("{}", s1);

  short int s2{ 14 };
  println ("{}", s2);

  signed short s3{ 15 };
  println ("{}", s3);

  signed short int s4{ 16 };
  println ("{}", s4);

  long l{ -7L };
  println ("{}", l);

  long long ll{ 14LL };
  println ("{}", ll);

  unsigned int ui{ 2U };
  println ("{}", ui);

  unsigned uj{ 5U };
  println ("{}", uj);

  unsigned short us{ 23U };
  println ("{}", us);

  unsigned long ul{ 5400UL };
  println ("{}", ul);

  unsigned long long ull{ 140ULL };
  println ("{}", ull);

  float f{ 7.2f };
  println ("{}", f);

  double d{ 7.2 };
  println ("{}", d);

  long double ld{ 16.98L };
  println ("{}", ld);

  char ch{ 'm' };
  println ("{}", ch);

  // char8_t  c8{ u8 'm' };
  // char16_t c16{ u 'm' };
  // char32_t c32{ U 'm' };

  wchar_t w{ L'm' };
  // println ("{}", w);

  bool b1{ true };
  println ("{}", b1);

  std::byte b2{ 42 };
  // println ("{}", b2);
}
