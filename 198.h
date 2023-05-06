#pragma once

#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        // f(x)=max(f(x-1),f(x-2)+v(x))
        //          not rub, rub
        vector<int> f(nums.size());
        
        f[0] = nums[0];
        f[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++)
        {
            f[i] = max(f[i - 1], f[i - 2] + nums[i]);
        }

        return f[nums.size()-1];
    }
};