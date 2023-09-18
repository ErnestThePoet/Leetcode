#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int maxValue = 0;
        int low = 0, high = height.size()-1;

        while (low < high)
        {
            maxValue = max(min(height[low], height[high]) * (high - low), maxValue);
            if (height[low] > height[high])
            {
                high--;
            }
            else
            {
                low++;
            }
        }

        return maxValue;
    }
};