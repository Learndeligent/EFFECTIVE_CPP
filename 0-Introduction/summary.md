# 导读

## 术语（Terminology）

- 声明式 declaration：告诉编译器某个东西的名称和类型（type），但略去细节，所以声明式只是用来告诉编译器有这个东西以及这个东西大致是什么样子，比如：

```cpp
extern int x; // 对象（object）声明式
std::size_t numDigits(int number); // 函数（function）声明式
class Widget; // 类（class）声明式
template<typename T> 
class GraphNode; // 模版-类（template）声明式
```

- 签名式 signature：就是函数的参数和返回类型，一个函数的签名等同于该函数的类型。
  - 比如numDigits函数的签名是std::size_t (int)。
  - 需要注意，c++对签名式的官方定义不包括函数的返回类型，这是从重载层面去定义的。
- 定义式 definition：提供编译器一些声明式所遗漏的细节。
  - 对于对象而言，定义式是编译器为此对象拨发内存的地点
  - 对于function或者function template而言，定义式提供了代码本体
  - 对于class或者class template而言，定义式列出它们的成员

```cpp
int x; // 对象的定义式，注意与声明式的区别
std::size_t numDigits(int num) {  // 函数的定义式
  std::size_t digitSoFar = 1;
  while ((number/=10) != 0) ++digitSoFar;
  return digitSoFar;
}
class Widget {  // 类的定义式
  Widget();
  ~Widget();
  ...
}
template <typename T> // template的定义式
class GraphNode {
  public:
    GraphNode();
    ~GraphNode();
    ...
}
```

- 初始化 initialization： “给予对象初值”的过程。对用户自定义类型的对象而言，初始化由构造函数执行。
  - 所谓default构造函数是一个可被调用而不带任何实参者。这样的构造函数要不没有参数，要不就是每个参数都有缺省值。
  - 包括几种方式：default构造函数以及自定义构造函数、拷贝构造函数、拷贝赋值函数、移动构造函数。如果一个函数入口是pass by value，那么就会调用拷贝构造函数。

## TR1 和 Boost

- TR1 （Technical Report 1）： 一份规范，描述加入c++标准程序库的诸多新功能。这些机能以新的class templates 和 function templates形式体现，针对的题目有hash tables，reference-counting smart pointers，regular expressions，以及更多，所有TR1组建都被置于命名空间tr1内，tr1嵌套于命名空间std内

- Boost是一个组织，亦是一个网站（<http://boost.org>），可提供可移植、同僚评审、源码开放的c++程序库。大多数TR1机能是以boost的工作为基础。在编译器厂商于其c++程序库中含入TR1之前，对那些搜寻TR1实现品的开发人员而言，Boost网站可能是第一个逗留点。Boost提供比TR1>更多的东西，所以无论如何值得了解它。
