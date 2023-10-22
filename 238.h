#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        vector<int> result(nums.size());
        int cur = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            cur *= nums[i];
            result[i + 1] = cur;
        }

        cur = 1;

        for (int i = nums.size() - 1; i > 0; i--)
        {
            cur *= nums[i];
            if (i == 1)
            {
                result[0] = cur;
            }
            else
            {
                result[i - 1] *= cur;
            }
        }

        return result;
    }
};