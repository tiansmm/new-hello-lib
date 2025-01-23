#include <iostream>
using namespace std;

class Lambda {
    public:
    Lambda(int& x, int& y) : x(x), y(y) {};
    int& x;  // 按引用捕获 x
    int& y;  // 按引用捕获 y

    void operator()() const {
        x += 5;
        y += 10;
        cout << "Inside lambda: x = " << x << ", y = " << y << endl;
    }
};

int main() {
    // main 的伪代码
    int x = 10, y = 20;
    Lambda lambda(x,y);  // 捕获外部变量的引用
    lambda();                // 调用闭包，修改 x 和 y
    cout << "After lambda: x = " << x << ", y = " << y << endl;
    return 0;
}