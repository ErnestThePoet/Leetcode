#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        int currentValue = nums[0];
        int currentValueCount = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == currentValue)
            {
                currentValueCount++;

                if (currentValueCount >= 3)
                {
                    nums.erase(nums.cbegin() + i);
                    i--;
                }
            }
            else
            {
                currentValue = nums[i];
                currentValueCount = 1;
            }
        }

        return nums.size();
    }
};