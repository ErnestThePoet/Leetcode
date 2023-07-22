#pragma once
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string lcp;

        for (int i=0;i<strs[0].size();i++)
        {
            bool match = true;
            for (int j = 1; j < strs.size(); j++)
            {
                if (i >= strs[j].size() || strs[j][i] != strs[0][i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                lcp += strs[0][i];
            }
            else
            {
                break;
            }
        }

        return lcp;
    }
};