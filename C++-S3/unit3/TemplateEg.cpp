#include <iostream>
using namespace std;

template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    int x = 5, y = 7;
    cout << "Max of x and y is: " << max(x, y) << endl;

    float a = 3.14, b = 2.71;
    cout << "Max of a and b is: " << max(a, b) << endl;

    string s1 = "hello", s2 = "world";
    cout << "Max of s1 and s2 is: " << max(s1, s2) << endl;

    return 0;
}
