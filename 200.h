#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>>& grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();

        vector<vector<bool>> v(m, vector<bool>(n, false));

        int count = 0;

        for (int mc = 0; mc < m; mc++)
        {
            for (int nc = 0; nc < n; nc++)
            {
                if (grid[mc][nc] == '1' && !v[mc][nc])
                {
                    count++;
                    dfs(grid, v, m, n, mc, nc);
                }
            }
        }

        return count;
    }

    void dfs(const vector<vector<char>>& grid,
        vector<vector<bool>>& v,
        const int m,
        const int n,
        const int mCur,
        const int nCur)
    {
        v[mCur][nCur] = true;

        if (mCur - 1 >= 0 && !v[mCur-1][nCur]&&grid[mCur - 1][nCur] == '1')
        {
            dfs(grid, v, m,n,mCur - 1, nCur);
        }

        if (mCur + 1 <m && !v[mCur + 1][nCur] && grid[mCur + 1][nCur] == '1')
        {
            dfs(grid, v, m, n, mCur + 1, nCur);
        }

        if (nCur - 1 >= 0 && !v[mCur][nCur-1] && grid[mCur][nCur-1] == '1')
        {
            dfs(grid, v, m, n, mCur, nCur - 1);
        }

        if (nCur + 1 <n && !v[mCur][nCur + 1] && grid[mCur][nCur + 1] == '1')
        {
			dfs(grid, v, m, n, mCur, nCur + 1);
        }
    }
};
