#include <iostream>
using namespace std;

class Integer
{
    public:
        Integer(int value = 0) : value_{ value } {}
        friend ostream& operator<<(ostream & os, const Integer & integer)
        {
            //return os << "Integer" << integer.value_;
            return os << integer.value_;
        }
    private:
        int value_;
};

int main()
{
    // one additional statement allowed!
    //copy(istream_iterator<int>{cin}, istream_iterator<int>{} , [](int a){cout << Integer(a);});
    copy(istream_iterator<int>{cin}, istream_iterator<int>{} , ostream_iterator<Integer>{cout});
    return 0;
}
