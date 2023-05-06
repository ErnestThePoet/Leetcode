#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        // len[i] is the length of LIS that ENDS WITH nums[i].
        vector<int> len(nums.size(), 1);

        int maxLisLen = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    len[i] = max(len[i], len[j] + 1);
                }
            }

            maxLisLen = max(maxLisLen, len[i]);
        }

        return maxLisLen;
    }
};