#include <iostream>
#include <fstream>

using namespace std;

class Ifcharstream
{
public:
    Ifcharstream (string const & filename);
    ~Ifcharstream ();
    char operator[](streampos i);

private:
    Ifcharstream() = delete;
    fstream fs;
};

Ifcharstream::Ifcharstream(string const & filename)
{
    fs.open(filename);
}

Ifcharstream::~Ifcharstream () {
    if (fs.is_open()) {
       fs.close();
    }
}

char Ifcharstream::operator[](streampos pos)
{
    fs.seekg(pos);
    char c;
    fs.read(&c, sizeof(char));
    return c;
}

int main()
{
    Ifcharstream ics {"ex.txt"};
    cout << ics[0] << ics[25] << endl;
    return 0;
}

