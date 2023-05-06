#include <iostream>
#include "64.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;

    vector<vector<int>> c = { {1,3,1},{1,5,1},{4,2,1} };

    cout << solution.minPathSum(c) << endl;

    return 0;
}