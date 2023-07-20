#pragma once
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> num_set;

        for (int num : nums)
        {
            num_set.insert(num);
        }

        // In case for []
        int longestStreak = 0;

        for (int num : nums)
        {
            if (num_set.find(num-1) == num_set.cend())
            {
                int currentStreak = 1;
                for (int i = num + 1; num_set.find(i) != num_set.cend(); i++)
                {
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};