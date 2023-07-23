#pragma once
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
        {
            return 0;
        }

        int longest_length = 1;

        unordered_set<char> us;

        int left = 0, right = 0;

        while (true)
        {
            while (right < s.size() && us.find(s[right]) == us.cend())
            {
                us.insert(s[right]);
                right++;
            }

            longest_length = max(longest_length, right - left);

            if (right >= s.size())
            {
                break;
            }

            while (left < right)
            {
                us.erase(s[left]);
                left++;
                if (s[left - 1] == s[right])
                {
                    break;
                }
            }
        }

        return longest_length;
    }
};