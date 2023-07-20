#include <iostream>
#include "128.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;

    vector<int> c = { 100,4,200,1,3,2 };

	cout << solution.longestConsecutive(c) << endl;

    return 0;
}