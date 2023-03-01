#include <iostream>
#include "../src/dynamicArray.h"

#include <vector>

using namespace shiny;
using namespace std;

int main()
{
    vector<int> vec;
    DynamicArray<int> arr([](int prevSize)->int { return prevSize * 3; });
    cout << arr.nextSize(2) << endl;
}