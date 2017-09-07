# Exercises: Basic langauge constructs

### 1

#### Question 
Which of the following declarations are definitions and which are not? Give a corresponding
definition for those that are not a definition and a corresponding declaration for those that are.

```
char c;
string s;
auto count{ 1 };
const int MAX{ 4711 };
extern double d;
const char* msg{ ”Hello!” };
const char* Direction[]{ ”up”, ”down”, ”left”, ”right” };
struct Time { int h, m, s; };
int sec(Time* p) { return p->s; }
double sqrt(double);
template<typename T> T abs(T a) { return (a < 0) ? -a : a; }
typedef std::vector<double> data;
using char_ptr = char*;
struct Node;
enum Season { Spring, Summer, Autumn, Winter };
namespace N { int i; }
```

##### Answer
```
char c;                                                         (definition)
string s;                                                       (definition)
auto count{ 1 };                                                (definition)
const int MAX{ 4711 };                                          (definition)
extern double d;                                                (declaration)
const char* msg{ ”Hello!” };                                    (definition)
const char* Direction[]{ ”up”, ”down”, ”left”, ”right” };       (definition)
struct Time { int h, m, s; };                                   (definition)
int sec(Time* p) { return p->s; }                               (definition)
double sqrt(double);                                            (declaration)
template<typename T> T abs(T a) { return (a < 0) ? -a : a; }    (definition)
typedef std::vector<double> data;                               (definition)
using char_ptr = char*;                                         (definition)
struct Node;                                                    (declaration)
enum Season { Spring, Summer, Autumn, Winter };                 (definition)
namespace N { int i; }                                          (definition)
```
