#include "Util.h"

int mod(int num, int base) {
  int res = num % base;
  return res >= 0 ? res : res + base;
}
