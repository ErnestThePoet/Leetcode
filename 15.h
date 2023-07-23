#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> answers;

        for (int i=0;i<nums.size();i++)
        {
            if (nums[i] > 0)
            {
                break;
            }

            const int num = nums[i];

            int low = i + 1, high = nums.size() - 1;

            while (true)
            {
                if (low>=nums.size()||high<0||low >= high)
                {
                    break;
                }

                const int lowNum = nums[low], highNum = nums[high];
                const int sum = num + lowNum + highNum;

                if (sum == 0)
                {
                    answers.emplace_back(vector<int>{ num, lowNum, highNum });

                    while (low < high && nums[low] == lowNum)
                    {
                        low++;
                    }

                    while (low < high && nums[high] == highNum)
                    {
                        high--;
                    }
                }
                else if (sum > 0)
                {
                    high--;
                }
                else
                {
                    low++;
                }
            }

            int prev = nums[i];

            while (i < nums.size() && nums[i] == prev)
            {
                i++;
            }

            i--;
        }

        return answers;
    }
};