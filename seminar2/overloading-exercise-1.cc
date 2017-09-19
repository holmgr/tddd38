#include <iostream>

using namespace std;

struct Person {
    std::string first_name;
    std::string last_name;
    std::string street;
    std::string postcode;
    std::string city;

    friend ostream& operator<<(ostream& os, Person const & p);
    friend istream& operator>>(istream& is, Person & p);
};

istream& operator>>(istream& is, Person & p)
{
    is >> p.first_name >> p.last_name >> ws;
    getline(is, p.street);
    getline(is, p.postcode);
    getline(is, p.city);
    return is;
}

ostream& operator<<(ostream& os, Person & p)
{
   os << p.first_name << ' ' << p.last_name << endl;
   os << p.street << endl;
   os << p.postcode << endl;
   os << p.city << endl;
   return os;
}

int main()
{
    Person p;
    cin >> p;
    cout << endl << p << endl << "Was the Person info" << endl;
    return 0;
}

