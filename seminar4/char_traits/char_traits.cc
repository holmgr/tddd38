#include <iosfwd>

template<typename charT> struct char_traits;

template<> struct char_traits<char>
{
    using char_type = char;
    using int_type = int;
    using pos_type = std::streampos;
    using off_type = std::streamoff;
    using state_type = mbstate_t;

    static void assign(char_type & c1, const char_type & c2)
    {
        c1 = c2;
    }

    static bool eq(const char_type & c1, const char_type & c2)
    {
        return c1 == c2;
    }

    static bool lt(const char_type & c1, const char_type & c2)
    {
        return c1 < c2;
    }

    static int compare(const char_type * s1, const char_type * s2, size_t n)
    {
        for (size_t i = 0; i < n; ++i) {
            if (lt(s1[i], s2[i])) {
               return -1; 
            }
            else if (lt(s2[i], s1[i])) {
               return 1; 
            }
        }
        return 0;

    }

    static size_t length(char_type * s)
    {
        size_t i;
        for (i = 0; eq(s[i], char()); ++i) {};
        return i;
    }

    static const char_type* find(const char_type * s, size_t n, const char_type & a)
    {
        size_t p;
        for (p = 0; p < n; ++p) {
            if (eq(a, s[p])) {
                return s + p; 
            }
        }
        return nullptr;
    }

    static char_type* move(char_type * s1, const char_type * s2, size_t n)
    {
        for (size_t i {}; i < n; ++i) {
           assign(s1[i], s2[i]); 
        }
        return s1;
    }

    static char_type* copy(char_type * s1, const char_type * s2, size_t n)
    {
        return move(s1, s2, n);
    }
};

int main()
{
    return 0;
}
