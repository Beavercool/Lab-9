#include <iostream>
#include <array>
#include <string>
#include <algorithm>
#include <typeinfo>
#define Tab endl
using namespace std;

template<typename T, size_t size>
string array_to_string(const array<T, size>& arr)
{
    string Res = "[";

    for (auto i : arr) {
        Res.append(to_string(i)).append(", ");
    }

    Res.erase(Res.end() - 2, Res.end());

    Res += "]";

    return Res;
}

template<typename T, size_t size>
T sum(const array<T, size>& arr)
{
    T Res = 0;

    for (auto i : arr)
    {
        Res += i;
    }

    return Res;
}

template<typename T, size_t size>
T average(const array<T, size>& arr)
{
    return T(sum(arr) / arr.size());
}

int main(int argc, char* argv[])
{
    array<int, size_t(5)> arr = { 10, 12, 62, 4, 44 };

    cout << "Original: " << array_to_string(arr) << Tab;

    sort(arr.begin(), arr.end());

    cout << "Sorting: " << array_to_string(arr) << Tab;

    cout << "Access to element with \".at()\": " << arr.at(1) << Tab;

    cout << "Access to element with \"operator []\": " << arr[2] << Tab;

    cout << "Summ: " << sum(arr) << Tab;

    cout << "Average: " << average(arr) << Tab;

    cout << "Place \"12\" in Array: " <<distance(arr.begin(), find(arr.begin(), arr.end(), 12)) << Tab;

    replace(arr.begin(), arr.end(), 62, 79);

    cout << "Replace element \" 52\"  on \" 79 \" in array: " << array_to_string(arr) << Tab;
    getchar();
}