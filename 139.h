#pragma once

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        unordered_set<string> words(wordDict.cbegin(), wordDict.cend());

        vector<bool> ok(s.size(),false);

        ok[0] = words.find(s.substr(0, 1)) != words.cend();

        for (int i = 1; i < s.size(); i++)
        {
            if (words.find(s.substr(0, i + 1)) != words.cend())
            {
                ok[i] = true;
                continue;
            }

            for (int j = 1; j <= i; j++)
            {
                if (ok[j - 1] && words.find(s.substr(j, i - j + 1)) != words.cend())
                {
                    ok[i] = true;
                    continue;
                }
            }
        }

        return ok[s.size() - 1];
    }
};