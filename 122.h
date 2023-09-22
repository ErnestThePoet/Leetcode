#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int hold = -prices[0], unhold = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            int curHold = max(hold, unhold - prices[i]);
            int curUnhold = max(hold + prices[i], unhold);

            hold = curHold;
            unhold = curUnhold;
        }

        return unhold;
    }
};