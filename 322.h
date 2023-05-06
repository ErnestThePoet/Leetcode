#pragma once

#include <vector>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        constexpr int kInf = 0x3f3f3f3f;
        vector<int> dp(amount+1, kInf);

        dp[0] = 0;

        for (auto coin : coins)
        {
            if (coin <= amount)
            {
                dp[coin] = 1;
            }
        }

        // a(i)=min({a(i-coin)|coin in coins AND i-coin>=0})+1
        for (int i = 1; i <= amount; i++)
        {
            for (auto coin : coins)
            {
                if (i - coin >= 0)
                {
                    dp[i] = min(dp[i], dp[i - coin]+1);
                }
            }
        }

        return dp[amount]>=kInf?-1:dp[amount];
    }
};