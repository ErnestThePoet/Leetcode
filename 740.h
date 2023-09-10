#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int>& nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int maxValue = *max_element(nums.cbegin(), nums.cend());

        vector<int> earns(maxValue + 1);

        for (int i : nums)
        {
            earns[i] += i;
        }

        int max_in_l2 = earns[0];
        int max_in_l1 = max(earns[0], earns[1]);

        for (int i = 2; i < earns.size(); i++)
        {
            int temp = max_in_l1;
            max_in_l1 = max(max_in_l2 + earns[i], max_in_l1);
            max_in_l2 = temp;
        }

        return max_in_l1;
    }
};