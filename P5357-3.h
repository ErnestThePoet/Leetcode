// This version elimishes some TLE

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>

using std::array;
using std::vector;
using std::queue;
using std::string;
using std::cin;
using std::cout;
using std::endl;

constexpr size_t kCharSetSize = 26;
constexpr int kRootIndex = 0;

#define GET_CHAR_INDEX(C) (C-'a')

struct TrieMapNode
{
	vector<int> terminated_pattern_indexes;
	array<int, kCharSetSize> sons;
	int fail;

	TrieMapNode() :fail(kRootIndex)
	{
		sons.fill(kRootIndex);
	}
};

vector<TrieMapNode> BuildTrieTree(const vector<string>& patterns)
{
	vector<TrieMapNode> tree(1);

	for (int i = 0; i < patterns.size(); i++)
	{
		int cur = kRootIndex;
		for (int j = 0; j < patterns[i].size(); j++)
		{
			if (tree[cur].sons[GET_CHAR_INDEX(patterns[i][j])]== kRootIndex)
			{
				tree[cur].sons[GET_CHAR_INDEX(patterns[i][j])] = tree.size();
				tree.emplace_back();
			}

			if (j == patterns[i].size() - 1)
			{
				tree[tree[cur].sons[GET_CHAR_INDEX(patterns[i][j])]].terminated_pattern_indexes.push_back(i);
			}

			cur = tree[cur].sons[GET_CHAR_INDEX(patterns[i][j])];
		}
	}

	return tree;
}

void BuildFail(vector<TrieMapNode>& tree)
{
	queue<int> q;

	for (int i = 0; i < kCharSetSize; i++)
	{
		if (tree[kRootIndex].sons[i]!= kRootIndex)
		{
			tree[tree[kRootIndex].sons[i]].fail = kRootIndex;
			q.push(tree[kRootIndex].sons[i]);
		}
	}

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < kCharSetSize; i++)
		{
			if (tree[cur].sons[i]!=kRootIndex)
			{
				tree[tree[cur].sons[i]].fail = tree[tree[cur].fail].sons[i];
				q.push(tree[cur].sons[i]);
			}
			else
			{
				tree[cur].sons[i] = tree[tree[cur].fail].sons[i];
			}
		}
	}
}

void P5357()
{
	int n;
	cin >> n;
	vector<string> patterns(n);
	string m;

	for (int i = 0; i < n; i++)
	{
		cin >> patterns[i];
	}

	cin >> m;

	vector<int> counts(n);

	auto tree = BuildTrieTree(patterns);

	BuildFail(tree);

	int cur_base = kRootIndex;
	for (int i = 0; i < m.size(); i++)
	{
		int cur = tree[cur_base].sons[GET_CHAR_INDEX(m[i])];
		while (cur != kRootIndex)
		{
			if (tree[cur].terminated_pattern_indexes.size())
			{
				for (int terminated_pattern_index : tree[cur].terminated_pattern_indexes)
				{
					counts[terminated_pattern_index]++;
				}
			}
			cur = tree[cur].fail;
		}

		cur_base = tree[cur_base].sons[GET_CHAR_INDEX(m[i])];
	}

	for (int count : counts)
	{
		cout << count << endl;
	}
}