#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    Point p = { 1 , 2 };             // C++98
    Point pp{ 1 , 2 };               // C++11
    Point parr[]{ {1, 2}, {3, 4} };  // C++11

    int a = 1;                       // C++98
    int b = { 2 };                   // C++11
    int b{ 2 };                      // C++11
    int b({ 2 });                    // C++11

    int* ptr = new int[5];           // C++98
    int* ptr = new int[5] {1, 2, 3}; // C++11

    int arr[10] = { 1, 2, 3, 4 };    // C++98
    vector<int> v = { 1,2, 3,4 };    // C++11

};