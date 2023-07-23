#include <iostream>
#include "209.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;

    vector<int> s{8};

    cout<<solution.minSubArrayLen(7,s);

    return 0;
}