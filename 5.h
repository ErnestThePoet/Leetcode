#pragma once
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));

        int longestLeft = 0, longestLength = 1;

        for (int i = 0; i < s.size(); i++)
        {
            dp[i][i] = true;
        }

        for (int length = 2; length <= s.size(); length++)
        {
            for (int left = 0; left <= s.size() - length; left++)
            {
                const int right = left + length - 1;

                if (length == 2)
                {
                    dp[left][right] = s[left] == s[right];
                }
                else
                {
                    dp[left][right] = dp[left + 1][right - 1] && s[left] == s[right];
                }

                if (dp[left][right])
                {
                    longestLeft = left;
                    longestLength = length;
                }
            }
        }

        return s.substr(longestLeft, longestLength);
    }
};