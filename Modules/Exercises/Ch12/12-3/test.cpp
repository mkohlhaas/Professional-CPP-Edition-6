import key_value_pair;
import std;

using namespace std;

int
main ()
{
  KeyValuePair<int, double> kv1{ 11, 2.33 };
  println ("{} = {}\n", kv1.getKey (), kv1.getValue ());

  // KeyValuePair kv2{ "John Doe"s, 123456 }; //// Now causes a compilation error.
}
