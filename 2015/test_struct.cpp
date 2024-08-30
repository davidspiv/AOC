#include <iostream>

using String = std::string;

struct torgle_register {
  unsigned int SN : 4;  // 4 bits for SN value
  unsigned int : 4;     // 4 bits unused
  bool goodIn : 1;      // valid input (1 bit)
  bool goodTorgle : 1;  // successful torgling
};

int main() {
  torgle_register tr = {14, true, false};

  std::cout << tr.SN << std::endl;

  return 0;
}
