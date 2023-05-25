#include <iostream>
#include "200.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;

    vector<vector<char>> c = { 
        {'1','1','0','0','0'} ,
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

	cout << solution.numIslands(c) << endl;

    return 0;
}