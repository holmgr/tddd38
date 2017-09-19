#include <iostream>
using namespace std;

class Integer
{
    public:
        Integer (int i): i_(i) {};

        // Unary operators
        Integer operator+();
        Integer operator-();

        // Binary operators
        friend Integer operator+(Integer const & lhs, Integer const & rhs);
        friend Integer operator-(Integer const & lhs, Integer const & rhs);
        friend Integer operator*(Integer const & lhs, Integer const & rhs);
        friend Integer operator/(Integer const & lhs, Integer const & rhs);
        friend Integer operator%(Integer const & lhs, Integer const & rhs);

        // Increment/decrement
        Integer operator++();
        Integer operator++(int); // Post increment
        Integer operator--();
        Integer operator--(int); // Post decrement

        // Steam operators
        friend std::istream& operator>>(std::istream& is, Integer & i);
        friend std::ostream& operator<<(std::ostream& os, Integer const & i);

    private:
        int i_;
};

Integer Integer::operator+() {
    return Integer(i_);
}

Integer Integer::operator-() {
    return Integer(-i_);
}

Integer operator+(Integer const & lhs, Integer const & rhs)
{
    return Integer(lhs.i_ + rhs.i_);
}

Integer operator-(Integer const & lhs, Integer const & rhs)
{
    return Integer(lhs.i_ - rhs.i_);
}

Integer operator*(Integer const & lhs, Integer const & rhs)
{
    return Integer(lhs.i_ * rhs.i_);
}

Integer operator/(Integer const & lhs, Integer const & rhs)
{
    return Integer(lhs.i_ / rhs.i_);

}

Integer operator%(Integer const & lhs, Integer const & rhs)
{
    return Integer(lhs.i_ % rhs.i_);
}

Integer Integer::operator++()
{
    ++i_;
    return *this;
}

Integer Integer::operator++(int)
{
    Integer tmp(i_);
    ++i_;
    return tmp;
}

Integer Integer::operator--()
{
    --i_;
    return *this;

}

Integer Integer::operator--(int)
{
    Integer tmp(i_);
    --i_;
    return tmp;
}

std::istream& operator>>(std::istream& is, Integer & i)
{
    return is >> i.i_;
}

std::ostream& operator<<(std::ostream& os, Integer const & i)
{
    return os << i.i_;
}

int main()
{
    Integer i(10);

    cout << "i   == " << i   << endl << endl;
    cout << "i++ == " << i++ << endl;
    cout << "i   == " << i   << endl;
    cout << "i-- == " << i-- << endl;
    cout << "i   == " << i   << endl << endl;

    cout << "++i == " << ++i << endl;
    cout << "i   == " << i   << endl;
    cout << "--i == " << --i << endl;
    cout << "i   == " << i   << endl << endl;

    cout << "+i == " << +i << endl;
    cout << "-i == " << -i << endl << endl;

    cout << "i + i == " << i + i << endl;
    cout << "i - i == " << i - i << endl;
    cout << "i * i == " << i * i << endl;
    cout << "i / i == " << i / i << endl;
    cout << "i % i == " << i % i << endl << endl;

    cout << "i + 5 == " << i + 5 << endl;
    cout << "5 + i == " << 5 + i << endl;

    cout << "i - 5 == " << i - 5 << endl;
    cout << "5 - i == " << 5 - i << endl << endl;

    cout << "i + 'A' == " << i + 'A' << endl;
    // cout << "i + 3.5 == " << i + 3.5 << endl;
}
