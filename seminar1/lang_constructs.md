# Exercises: Basic langauge constructs

## Basic langauge features
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

### 2

#### Question
Which entities in exercise 1 have a size, i.e. to which may the operator sizeof be applied?

##### Answer
```
char c;                                                         (has size)
string s;                                                       (has size)
auto count{ 1 };                                                (has size)
const int MAX{ 4711 };                                          (has size)
extern double d;                                                (has size)
const char* msg{ ”Hello!” };                                    (has size)
const char* Direction[]{ ”up”, ”down”, ”left”, ”right” };       (has size)
struct Time { int h, m, s; };                                   (has size)
int sec(Time* p) { return p->s; }                               (no size)
double sqrt(double);                                            (no size)
template<typename T> T abs(T a) { return (a < 0) ? -a : a; }    (no size)
typedef std::vector<double> data;                               (has size)
using char_ptr = char*;                                         (has size)
struct Node;                                                    (no size)
enum Season { Spring, Summer, Autumn, Winter };                 (has size)
namespace N { int i; }                                          (no size)
```
**Can't take sizeof functions and namespaces, as well as undefined structs**

### 3

#### Question
Write declarations for the following entities and initialize each of them:

* a pointer to char
* an array with 10 int
* a reference to an array with 10 int
* a pointer to an array with 10 elements of type string
* a pointer to a pointer to char
* a constant int
* a pointer to a constant int
* a constant pointer to an int

##### Answer
```
char* chr_ptr = new char {'a'};

int arr[10] {};

int (&arr_ptr)[10] {};

string str_arr[10] {"Hello"};
string (*str_arr_ptr)[10] { &str_arr };

char** chr_ptr_ptr { &chr_ptr };

int const integer {42};

int const * int_ptr { &integer };

int* const int_const_ptr { new int { 42 } };
```

### 4

#### Question
Use alias declarations (using) to define the following types, in the given order:
* unsigned char
* const unsigned char
* pointer to int
* pointer to pointer to char
* pointer to array with element of type char
* array with 10 pointer to int
* pointer to an array with 10 pointer to int
* array 20 of array 10 with pointer to int

##### Answer
```
using uchar = unsigned char;

using cuchar = unsigned const char;

using i_ptr = int*;

using chr_ptr_ptr = char**;

using chr_arr_ptr = char*;

using int_arr = int*[10];

using int_arr_ptr = int*[10]*;

using arr_arr_ptr = int*[20][10];
```

### 5

#### Question
For each of the following declarations: Is it legal? If it is, what does it declare?
```
int a(int i);
int a(int);
int a(int (i));
int a(int (*b)());
int a(int b());
int a(int ());
```

##### Answer
```
int a(int i);       // Function A taking one int argument i
int a(int);         // Function A taking one int
int a(int (i));     // Redundant paranthesis around i
int a(int (*b)());  // Function A taking a function b which returns an int taking no arguments
int a(int b());     // Implicit function pointer
int a(int ());      // Function pointer with name omitted
```

### 6

#### Question
What does the following mean? How can it be used?
using x = int(&)(int, int);

##### Answer
X is a reference to a function taking two ints and returning an int

### 7

#### Question
Which size does the character array msg have? Which length does the string "Hello world!" have?

```
char msg[]{ "Hello world!" };
```

##### Answer
The length of `msg` should be that of a `char*`, whereas the length of the string is 13 (including null terminator)


### 8

#### Question
Which value, in principle, does the operator sizeof give for the following variables?

```
char str1[100]{ "String" };
char str2[]{ "String" };
const char* str3{ "String" };
string str4{ "String" };
```

##### Answer
```
char str1[100]{ "String" };     // 100
char str2[]{ "String" };        // 7
const char* str3{ "String" };   // 8 (size of char*)
string str4{ "String" };        // 32 (size of string object in memory)
```

### 9

#### Question
Fully parenthesize each of the following expressions:

```
a = b+c*d<<2&8
a&&077!=3
a==b || a==c && c<5
c = x!=0
0<=i<7
f(1,2)+3
a = -1+ +b-- -5
a= b==c++
a = b = c = 0
a[4][2] *= *b? c: *d*2
a-b, c = d
*p++
*--p
++a--
(int*)p->m
*p.m
*a[i]
```
How will the seventh expression above be parsed, if one removes all spaces? Will it be a legal
expression? Will it be semantically the same as the expression with spaces?
Note: This illustrates the maximum munch principle used by the parser.

##### Answer
```
a = (((b+(c*d))<<2)&8);
((a&&077)!=3)
((a==b) || ((a==c) && c<5))
(c = (x!=0))
(0<=(i<7))
(f(1,2))+3
a = -1+ +b-- -5
a= b==c++
a = b = c = 0
a[4][2] *= *b? c: *d*2
a-b, c = d
*p++
*--p
++a--
(int*)p->m
*p.m
*a[i]
```
No we cannot remove all spaces (`1++` causes error)

### 10

#### Question
Write declarations for the following types, in the order given. Show both alias declarations
(using) and typedefs.
* a function which takes two arguments, one of type pointer to char and one of type reference to int, not returning anything
* a pointer to such a function
* a function which takes such a function pointer as argument
* a function which returns such a pointer

##### Answer

```
using first = void(*)(char*, &int);

using second = void(first);

using third = void(*)(first);

using forth = first(*)();
```

### 11

#### Question
Given the declarations:
```
unsigned u = 0;
bool b = false;
double d = 0.0;
```
What results will the following expressions give, and what value will the three variables have
afterwards if, of course, the expression in question is legal?

```
u-- and thereafter ++u
b++ and thereafter, again b++
++b
b--
--b
d++
```
The operand to an increment operator must be a modifiable lvalue, but what is the result of
postfix ++/-- and prefix ++/--, respectively? Is it a lvalue or a rvalue?

##### Answer
```
u-- and thereafter ++u          // u is zero
b++ and thereafter, again b++   // b is 1 (0->1->1)
++b                             // b is 1
b--                             // not legal
--b                             // not legal
d++                             // d is 1.0
```
