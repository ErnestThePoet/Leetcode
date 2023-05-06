#include <iostream>
#include "300.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;

    vector<int> c = { 10,9,2,5,3,7,101,18 };

    cout << solution.lengthOfLIS(c) << endl;

    return 0;
}