#include <cstddef>
#include <print>

using std::println;

int
main ()
{
  int i1{ -7 };
  println ("{}", i1);
  println ("int: {}", sizeof (i1));

  signed int i2{ -6 };
  println ("{}", i2);
  println ("signed int: {}", sizeof (i2));

  signed i3{ -5 };
  println ("{}", i3);
  println ("signed: {}", sizeof (i3));

  short s1{ 13 };
  println ("{}", s1);
  println ("short: {}", sizeof (s1));

  short int s2{ 14 };
  println ("{}", s2);
  println ("short int: {}", sizeof (s2));

  signed short s3{ 15 };
  println ("{}", s3);
  println ("signed short: {}", sizeof (s3));

  signed short int s4{ 16 };
  println ("{}", s4);
  println ("signed short int: {}", sizeof (s4));

  long l{ -7L };
  println ("{}", l);
  println ("long: {}", sizeof (l));

  long long ll{ 14LL };
  println ("{}", ll);
  println ("long long: {}", sizeof (ll));

  unsigned int ui{ 2U };
  println ("{}", ui);
  println ("unsigned int: {}", sizeof (ui));

  unsigned uj{ 5U };
  println ("{}", uj);
  println ("unsigned: {}", sizeof (uj));

  unsigned short us{ 23U };
  println ("{}", us);
  println ("unsigned short: {}", sizeof (us));

  unsigned long ul{ 5400UL };
  println ("{}", ul);
  println ("unsigned long: {}", sizeof (ul));

  unsigned long long ull{ 140ULL };
  println ("{}", ull);
  println ("unsigned long long: {}", sizeof (ull));

  float f{ 7.2f };
  println ("{}", f);
  println ("float: {}", sizeof (f));

  double d{ 7.2 };
  println ("{}", d);
  println ("double: {}", sizeof (d));

  long double ld{ 16.98L };
  println ("{}", ld);
  println ("long double: {}", sizeof (ld));

  char ch{ 'm' };
  println ("{}", ch);
  println ("char: {}", sizeof (ch));

  // char8_t  c8{ u8 'm' };
  // char16_t c16{ u 'm' };
  // char32_t c32{ U 'm' };

  wchar_t w{ L'm' };
  // println ("{}", w);
  println ("wchar: {}", sizeof (w));

  bool b1{ true };
  println ("{}", b1);
  println ("bool: {}", sizeof (b1));

  std::byte b2{ 42 };
  // println ("{}", b2);
  println ("std::byte: {}", sizeof (b2));
}
