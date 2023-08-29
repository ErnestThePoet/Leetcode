#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> nums3(nums1.cbegin(), nums1.cbegin() + m);

        int curFill = 0;
        int cur2 = 0,cur3=0;

        while (cur2 < nums2.size() && cur3 < nums3.size())
        {
            if (nums2[cur2] < nums3[cur3])
            {
                nums1[curFill++] = nums2[cur2++];
            }
            else
            {
                nums1[curFill++] = nums3[cur3++];
            }
        }

        while (cur2 < nums2.size())
        {
            nums1[curFill++] = nums2[cur2++];
        }

        while (cur3 < nums3.size())
        {
            nums1[curFill++] = nums3[cur3++];
        }
    }
};