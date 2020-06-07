#include <functional>
#include <iostream>
#include <string>

using namespace std::placeholders;

class Test {
public:
    Test(int v_t)
        : v_(v_t)
    {
        auto callback_test = std::bind(&Test::callback_handler, this, _1);
        callback_test(100);
    }
    ~Test() {}
    void SetValue(int i) { v_ = i; }

    void callback_handler(int p_t)
    {
        std::cout << "callback in class: " << p_t << std::endl;
    }

    int v_;
};

int main()
{
    Test a{ 123 };

    std::cout << "test callback in main" << std::endl;
    std::cout << a.v_ << std::endl; // print 123

    auto _callback = std::bind(&Test::SetValue, &a, _1); // create the callback
    _callback(55); // call the callback

    std::cout << a.v_ << std::endl; // print 55

    return 0;
}
