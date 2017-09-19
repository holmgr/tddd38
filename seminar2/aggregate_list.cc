#include <iostream>

using namespace std;

void arr_fun(std::initializer_list<int> lst) {
    for (auto i : lst) {
        cout << i << endl;
    }
}

std::initializer_list<int> arr_fun2() {
    return {1, 2, 3};
}

struct ArrStr {
    int mem[3] {1, 2, 3};
    int mem2[3];
    ArrStr(): mem2 {1,2,3} {};
};

// 8 not possible, mem needs to be initializer_list
/*
struct ArrStr2 {
    int mem[3];
    ArrStr2(std::initializer_list<int> lst): mem {lst} {};
};
*/


int main()
{
    // Array
    int arr[3] {1, 2, 3};                       // 1
    int *arr_ptr = new int[3] {1, 2, 3};        // 2
    arr_fun({1, 2, 3});
    arr_fun(arr_fun2());
    ArrStr arrstr;

    // arr = {4, 5, 6};                         // 7 not assignable

}

