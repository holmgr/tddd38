#include <iostream>

class Integer
{
public:
    Integer (int i): i_(i) {}
    operator int() const { return i_; }

private:
    int i_;
};

struct Ten {
    operator Integer() const { return Integer(10); }
};


int main()
{

    Integer i(10); // Constructor Integer(int) is supposed to be defined
    const char* hex = "0123456789ABCDEF";
    char d = hex[i];

    std::cout << d << std::endl;
    Ten ten {};

    //Cannot do double implicit conversion
    // d = hex[ten];

    // Single explicit conversion, single implicit
    d = hex[ten.operator Integer()];

    // Double explicit conversion
    d = hex[ten.operator Integer().operator int()];
    std::cout << d << std::endl;
    return 0;
}
