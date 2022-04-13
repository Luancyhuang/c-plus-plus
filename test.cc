#include <iostream>
#include <vector>

int main()
{
  size_t sz;
  std:: vector<int> foo;
  sz = foo.capacity();
  std:: cout << "making foo grow:\n";

  for(int  i = 0; i < 100; ++i)
  {
    foo.push_back(i);
    if(sz != foo.capacity())
    {
      sz = foo.capacity();
      std:: cout << "capacity changed:" << sz << '\n';
    }
  }
  return 0;
}

