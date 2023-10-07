#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int prevMaxIndex = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (prevMaxIndex >= i)
            {
                prevMaxIndex = max(prevMaxIndex, i + nums[i]);
            }
        }

        return prevMaxIndex >= nums.size() - 1;
    }
};