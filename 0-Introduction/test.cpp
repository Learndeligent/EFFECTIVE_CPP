#include <iostream>

extern int a;
std::size_t func(int number);
class Widget {
public:
  Widget() { std::cout << "ctor" << std::endl; }
  ~Widget() { std::cout << "dtor" << std::endl; }
};

#include <memory>
#include <tr1/memory>

int main() {
  std::tr1::shared_ptr<Widget> shared_(new Widget());

  std::cout << func << std::endl;
  std::cout << "hello world" << std::endl;
}