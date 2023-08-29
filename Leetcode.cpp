#include <iostream>
#include "189.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;

    vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int i = 0; i < 15; i++)
    {
        vector<int> b = a;
        solution.rotate(b, i);

        for (auto i : b)
        {
            cout << i << ' ';
        }

        cout << '\n';
    }


    return 0;
}