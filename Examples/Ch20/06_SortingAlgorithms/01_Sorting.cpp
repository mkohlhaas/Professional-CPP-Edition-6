import std;

using namespace std;

// Function template to populate a container of ints.
// A constraint enforces that the container supports push_back(int).
template <typename Container>
requires
requires (Container &c, int i)
{
  c.push_back (i);
}
void
populateContainer (Container &cont)
{
  while (true)
    {
      print ("Enter a number (0 to stop): ");
      int value;
      cin >> value;
      if (value == 0)
        {
          break;
        }
      cont.push_back (value);
    }
}

int
main ()
{
  vector<int> values;
  populateContainer (values);

  sort (begin (values), end (values), greater<>{});

  println ("{:n}", values);
}
