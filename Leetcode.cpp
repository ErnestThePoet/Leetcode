#include <iostream>
#include "88.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;

    vector<int> a{1, 2, 3, 5, 7,0,0,0,0,0,0,0};
    vector<int> b{1, 1,2,2, 3, 4,7};

    solution.merge(a, 5, b, 7);

    for (auto i : a)
    {
        cout << i << endl;
    }

    return 0;
}