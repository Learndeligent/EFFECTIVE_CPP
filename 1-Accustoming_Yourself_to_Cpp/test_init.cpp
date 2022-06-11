#include <iostream>

class A {
public:
  A() {
    std::cout << "A()" << std::endl;
  }
  ~A() {
    std::cout << "~A()" << std::endl;
  }
};

class B {
public:
  B() {
    std::cout << "B()" << std::endl;
  }
  ~B() {
    std::cout << "~B()" << std::endl;
  }
private:
  A a;
};

int main() {
  B b;

  return 0;
}