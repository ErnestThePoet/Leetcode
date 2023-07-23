#pragma once
#include <vector>

using namespace std;

class Solution
{
private:
	const int offset_x_[4] = { -1,0,1,0 };
	const int offset_y_[4] = { 0,-1,0,1 };

	void dfs(const vector<vector<char>>& board,
		vector<vector<bool>>& visited,
		const int y,
		const int x)
	{
		const int m = board.size();
		const int n = board[0].size();

		visited[y][x] = true;

		for (int i = 0; i < 4; i++)
		{
			const int new_x = x + offset_x_[i];
			const int new_y = y + offset_y_[i];

			if (0 <= new_x
				&& new_x < n
				&& 0 <= new_y
				&& new_y < m
				&& board[new_y][new_x] == 'O'
				&& !visited[new_y][new_x])
			{
				dfs(board, visited, new_y, new_x);
			}
		}
	}

public:
	void solve(vector<vector<char>>& board)
	{
		const int m = board.size();
		const int n = board[0].size();

		vector<vector<bool>> visited(m, vector<bool>(n, false));

		for (int i = 0; i < m; i++)
		{
			if (board[i][0] == 'O' && !visited[i][0])
			{
				dfs(board, visited, i, 0);
			}

			if (board[i][n - 1] == 'O' && !visited[i][n - 1])
			{
				dfs(board, visited, i, n - 1);
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (board[0][i] == 'O' && !visited[0][i])
			{
				dfs(board, visited, 0, i);
			}

			if (board[m - 1][i] == 'O' && !visited[m - 1][i])
			{
				dfs(board, visited, m - 1, i);
			}
		}

		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == 'O' && !visited[i][j])
				{
					board[i][j] = 'X';
				}
			}
		}
	}
};