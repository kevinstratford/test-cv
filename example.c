
#include <stdio.h>

#include "example.h"


int function1(int a) {

  if(a > 10) {
    return a + 1;
  }

  return 2;
}

int function2(void) {

  int a = 1;
  return ++a;
}

int function3(small_t arg) {

  printf("Small type: %ld\n", sizeof(small_t));
  printf("Values: %f %f ...\n", arg.data[0], arg.data[1]);

  return 0;
}

int function4(medium_t arg) {

  printf("Medium type: %ld\n", sizeof(medium_t));
  printf("Values: %f %f ...\n", arg.data[0], arg.data[1]);

  return 0;
}

int function5(large_t arg) {

  printf("Large type: %ld\n", sizeof(large_t));
  printf("Values: %f %f ...\n", arg.data[0], arg.data[1]);

  return 0;
}
