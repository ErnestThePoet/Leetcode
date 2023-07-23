#pragma once
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int low = 0, high = s.size() - 1;

        while (true)
        {
            while (low < s.size() && !isalnum(s[low]))
            {
                low++;
            }

            while (high >=0 && !isalnum(s[high]))
            {
                high--;
            }

            if (low >= s.size() || high < 0 || low >= high)
            {
                return true;
            }

            if (tolower(s[low]) == tolower(s[high]))
            {
                low++;
                high--;
            }
            else
            {
                return false;
            }
        }
    }
};