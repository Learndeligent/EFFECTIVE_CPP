#include <iostream>

class A {
  public:
    A(int a_): a(a_) {
      std::cout << "default constructor!" << std::endl;
    }
    A(const A& aa): a(aa.a) {
      std::cout << "copy constructor!" << std::endl;
    }
    A& operator=(const A& aa) {
      std::cout << "A operator = " << std::endl;
      a = aa.a;
      return *this;
    }
    ~A() {
      std::cout << "decons" << std::endl;
    }
    int a = 1;
};

void f1(const A* a) {
  std::cout << "Hello f1 version1" << std::endl;
}

void f2(A const *a) {
  std::cout << "Hello f2 version2" << std::endl;
}

const A get_const_A() {
  return A(2);
}

A get_nonconst_A() {
  return A(1);
}

void ff1(const A a) {
  std::cout << "ff1" << std::endl;
}

void ff2(A a) {
  std::cout << "ff2" << std::endl;
}


int main() {
  const A aInstance(2);
  f1(&aInstance);
  f2(&aInstance);

  // 通过在函数的返回值上面加const可以保证函数的返回值不被赋值
  // get_const_A() = A(1);
  get_nonconst_A() = A(1);
  // 这句执行完毕之后会连续调用两次析构函数

  ff1(aInstance);
  ff2(aInstance);

  return 0;
}