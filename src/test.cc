#include "include/mguard.h"
#include <string>

struct foo {
  int a;
  int b;
  std::string name;  
};

int main(int argc, char *argv[])
{
  EN_DEBUG_LOG(true);

  foo* f[5];

  for (auto i : {1,2,3,4,5}) {
    f[i-1] = new foo();
  }

  for (auto i : {1,2,3,4,5}) {
    delete f[i-1];
  }

  return 0;
}
