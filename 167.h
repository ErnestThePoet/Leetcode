#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        int low = 0, high = numbers.size() - 1;

        while (low < high)
        {
            const int cur = numbers[low] + numbers[high];
            if (cur == target)
            {
                return { low + 1,high + 1 };
            }
            else if (cur < target)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

        return { -1,-1 };
    }
};