#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return 0;
        }

        int prevMaxIndex = nums[0];
        int candidatePrevMaxIndex = nums[0]; // New max index within prevMaxIndex
        int prevSteps = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (prevMaxIndex >= nums.size() - 1)
            {
                return prevSteps;
            }

            if (prevMaxIndex < i)
            {
                prevMaxIndex = candidatePrevMaxIndex;
                prevSteps++;
            }

            candidatePrevMaxIndex = max(candidatePrevMaxIndex, i + nums[i]);
        }

        return prevSteps;
    }
};