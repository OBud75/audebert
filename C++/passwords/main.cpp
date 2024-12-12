#include <cassert>
#include "password.hpp"


int main (int argc, char *argv[]) {
  Password pass = Password("987465"); 
  std::cout << pass << std::endl;

  auto saved_password = pass.str();
  auto pass2 = Password(saved_password, true);

  assert(pass == pass2);

  return 0;
}
