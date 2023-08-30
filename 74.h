#pragma once
#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    int GetMatrixElementFromIndex(const vector<vector<int>>& matrix, const int x)
    {
        const int m = matrix[0].size();
        const int row = x / m;
        const int col = x - row * m;
        return matrix[row][col];
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        const int n = matrix.size() * matrix[0].size();

        int low = 0, high = n - 1;

        while (low <= high)
        {
            const int mid = (low + high) / 2;

            const int current = GetMatrixElementFromIndex(matrix, mid);
            if (current == target)
            {
                return true;
            }
            else if (current < target)
            {
                low=mid+1;
            }
            else
            {
                high = mid - 1;
            }
        }

        return false;
    }
};