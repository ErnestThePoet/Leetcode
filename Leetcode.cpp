#include <iostream>
#include "56.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;

    vector<vector<int>> v{
        {1, 2},
        { 2,2 },
        { 5,2 },
        { 3,2 },
    };

    solution.merge(v);

    return 0;
}