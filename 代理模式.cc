// 测试程序.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <vector>

using namespace std;
 
class  Subject {
public:
  virtual void Request() = 0;
  virtual ~Subject() {};

};

class RealSubject : public Subject {
public :
  void Request() {
    cout << "real subject" << std::endl;
  }
};

class Proxy : public Subject {
private :
  RealSubject* real_sub_;
public:
  void Request() {
    if (real_sub_ == nullptr) {
      real_sub_ = new RealSubject();
      real_sub_->Request();
    }
  }

};

int main()
{
  Proxy* proxy = new Proxy();
  proxy->Request();

  system("pause");
  return 0;
}

