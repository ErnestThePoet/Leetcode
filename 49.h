#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        vector<bool> is_categorized(strs.size(), false);
        vector<vector<string>> result;
        int empty_string_count = 0;

        vector<string> sorted = strs;
        for (auto& s : sorted)
        {
            sort(s.begin(), s.end());
        }

        for (int i = 0; i < strs.size(); i++)
        {
            if (is_categorized[i])
            {
                continue;
            }

            is_categorized[i] = true;

            if (strs[i].size() == 0)
            {
                empty_string_count++;
                continue;
            }

            vector<string> current_category{strs[i]};

            for (int j = i + 1; j < strs.size(); j++)
            {
                if (sorted[i] == sorted[j])
                {
                    current_category.push_back(strs[j]);
                    is_categorized[j] = true;
                }
            }

            result.emplace_back(std::move(current_category));
        }

        if (empty_string_count > 0)
        {
            result.emplace_back(vector<string>(empty_string_count, ""));
        }

        return result;
    }
};