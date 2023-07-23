#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int min_len = INT_MAX;

        int left = 0, right = 0;

        int sum = 0;

        while (true)
        {
            // R-Expand
            while (sum < target&&right<nums.size())
            {
                sum += nums[right];
                right++;
            }

            // L-Follow
            while (sum >= target && left < right)
            {
                min_len = min(min_len, right - left);
                sum -= nums[left];
                left++;
            }

            if (right >= nums.size())
            {
                break;
            }
        }

        return min_len == INT_MAX ? 0 : min_len;
    }
};