import std;

using namespace std;

class Muffin final
{
public:
  const string &
  getDescription () const
  {
    return m_description;
  }
  void
  setDescription (string description)
  {
    m_description = std::move (description);
  }

  int
  getSize () const
  {
    return m_size;
  }
  void
  setSize (int size)
  {
    m_size = size;
  }

  bool
  hasChocolateChips () const
  {
    return m_hasChocolateChips;
  }
  void
  setHasChocolateChips (bool hasChips)
  {
    m_hasChocolateChips = hasChips;
  }

  void
  output () const
  {
    printf ("%s, size is %d, %s", getDescription ().c_str (), getSize (),
            (hasChocolateChips () ? "has chips" : "no chips"));
  }

private:
  string m_description;
  int    m_size{ 0 };
  bool   m_hasChocolateChips{ false };
};

int
main ()
{
  println ("Let's create a muffin in code and print it.");

  Muffin myMuffin;
  myMuffin.setDescription ("Giant Blueberry Muffin");
  myMuffin.setSize (42);
  myMuffin.setHasChocolateChips (false);

  printf ("The muffin is a ");
  myMuffin.output ();
  printf (" -- yummy!\n");
}
