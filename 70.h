#pragma once
class Solution
{
public:
    int climbStairs(int n)
    {
        // f(x)=f(x-1)+f(x-2)
        if (n == 1)
        {
            return 1;
        }

        if (n == 2)
        {
            return 2;
        }

        int fx=3,fx1 = 2,fx2=1;
        for (int i = 2; i < n; i++)
        {
            fx = fx1 + fx2;
            fx2 = fx1;
            fx1 = fx;
        }

        return fx;
    }
};