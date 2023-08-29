#pragma once
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    void rotate(vector<int>& nums, int k)
    {
        k = k % nums.size();
        if (k == 0)
        {
            return;
        }

        vector<int> copied(nums.cbegin(), nums.cend());
        copy(copied.cbegin(), copied.cbegin() + copied.size() - k, nums.begin() + k);
        copy(copied.cend()-k, copied.cend(), nums.begin());
    }
};