#include <iostream>

class A {
public:
  int a[10] = {0};
  const int& operator[](std::size_t pos) const {
    std::cout << "const []" << std::endl;
    return a[pos];
  }
  int& operator[](std::size_t pos) {
    std::cout << "non-const []" << std::endl;
    return a[pos];
  }
  ~A() {
    std::cout << "decons" << std::endl;
  }
};

int main()
{
  const A a_const;
  A a_non_const;

  a_const[1];
  // a_const[1] = 1;
  a_non_const[2];
  std::cout << "before value: " << a_non_const[2] << std::endl;
  a_non_const[2] = 1;
  std::cout << "before value: " << a_non_const[2] << std::endl;

  return 0;
}