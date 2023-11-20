#include <memory>
#include <iostream>
#include <format>

/*interface*/ 
struct Base {
    virtual auto value() const -> int { return value_; }

    Base(int v) : value_{v} {}
    int value_ = 0;
};

struct Intermediate1 : Base {
    Intermediate1() : Base{111} {}
};

struct Intermediate2 : Base {
    Intermediate2() : Base{222} {}
};

struct Derived : Intermediate1, Intermediate2 {
    Derived() {}
};

int main() {

    auto i1 = std::make_unique<Intermediate1>();
    auto i2 = std::make_unique<Intermediate2>();
    std::cout << "i1 = " <<  i1->value() << "  i2 = " << i2->value() << "\n";

    auto d = std::make_unique<Derived>();
    std::cout << "d  = " << d->value() << "\n";
}














//     virtual auto value() const -> int override { 
//         return Intermediate1::value() + Intermediate2::value(); 
//     }  







// struct Derived : Intermediate1, Intermediate2 {
//     Derived() : Base{333} {}

//     virtual auto value() const -> int override { 
//         return Intermediate1::value() + Intermediate2::value(); 
//     }  
// };
