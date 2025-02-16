#include "GridDefault.h"
#include <deque>
#include <vector>

using namespace std;

int
main ()
{
  Grid<int, deque<optional<int> > >  myDequeGrid;
  Grid<int, vector<optional<int> > > myVectorGrid;
  Grid<int>                          myVectorGrid2{ myVectorGrid };
}
