
#include <assert.h>
#include "example.h"

int main(int argc, char ** argv) {

  small_t s = {0};

  assert(function1(5) == 2);
  assert(function2()  == 2);
  assert(function1(20) == 21);

  function3(s);

  return 0;
}
