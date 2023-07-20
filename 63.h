#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
    {
        const int width = obstacleGrid[0].size();
        const int height = obstacleGrid.size();
        
        vector<vector<int>> dp(height, vector<int>(width,0));

        bool isObstacleEncountered = false;
        for (int i = height - 1; i >= 0; i--)
        {
            if (obstacleGrid[i][width - 1])
            {
                isObstacleEncountered = true;
                continue;
            }

            dp[i][width - 1] = isObstacleEncountered ? 0 : 1;
        }

        isObstacleEncountered = false;

        for (int i = width - 1; i >= 0; i--)
        {
            if (obstacleGrid[height - 1][i])
            {
                isObstacleEncountered = true;
                continue;
            }

            dp[height - 1][i] = isObstacleEncountered ? 0 : 1;
        }

        for (int i = height - 2; i >= 0; i--)
        {
            for (int j = width - 2; j >= 0; j--)
            {
                if (obstacleGrid[i][j])
                {
                    continue;
                }

                // No need to check whether right and bottom are obstacles
                dp[i][j] = dp[i + 1][j]+dp[i][j + 1];
            }
        }

        return dp[0][0];
    }
};