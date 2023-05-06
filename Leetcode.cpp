#include <iostream>
#include "139.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Solution solution;
    vector<string> words = { "cats", "dog", "sand", "and", "cat" };

    cout << solution.wordBreak("sandanddogandcat",words) << endl;
    cout << solution.wordBreak("v1", words) << endl;

    return 0;
}