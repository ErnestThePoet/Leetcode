#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int minPrice = prices[0];
        int maxProfit = 0;

        for (auto price : prices)
        {
            if (price < minPrice)
            {
                minPrice = price;
            }
            else
            {
                if (price - minPrice > maxProfit)
                {
                    maxProfit = price - minPrice;
                }
            }
        }

        return maxProfit;
    }
};