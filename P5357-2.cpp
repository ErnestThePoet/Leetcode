// This version elimishes MLE

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <queue>
#include <memory>

using std::shared_ptr;
using std::make_shared;
using std::array;
using std::vector;
using std::queue;
using std::string;
using std::cin;
using std::cout;
using std::endl;

constexpr size_t kCharSetSize = 26;

#define GET_CHAR_INDEX(C) (C-'a')

struct TrieMapNode2
{
	vector<int> terminated_pattern_indexes;
	array<shared_ptr<TrieMapNode2>, kCharSetSize> sons;
	shared_ptr<TrieMapNode2> fail;
};

shared_ptr<TrieMapNode2> BuildTrieTree2(const vector<string>& patterns)
{
	shared_ptr<TrieMapNode2> root = make_shared<TrieMapNode2>();

	for (int i = 0; i < patterns.size(); i++)
	{
		auto cur = root;
		for (int j = 0; j < patterns[i].size(); j++)
		{
			if (!cur->sons[GET_CHAR_INDEX(patterns[i][j])])
			{
				cur->sons[GET_CHAR_INDEX(patterns[i][j])] = make_shared<TrieMapNode2>();
			}

			if (j == patterns[i].size() - 1)
			{
				cur->sons[GET_CHAR_INDEX(patterns[i][j])]->terminated_pattern_indexes.push_back(i);
			}

			cur = cur->sons[GET_CHAR_INDEX(patterns[i][j])];
		}
	}

	return root;
}

void BuildFail2(shared_ptr<TrieMapNode2>& root)
{
	queue<shared_ptr<TrieMapNode2>> q;

	root->fail = root;

	for (int i=0;i<kCharSetSize;i++)
	{
		if (root->sons[i])
		{
			root->sons[i]->fail = root;
			q.push(root->sons[i]);
		}
		else
		{
			root->sons[i] = root;
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i=0;i<kCharSetSize;i++)
		{
			if (cur->sons[i])
			{
				cur->sons[i]->fail = cur->fail->sons[i];
				q.push(cur->sons[i]);
			}
			else
			{
				cur->sons[i] = cur->fail->sons[i];
			}
		}
	}
}

void P5357_2()
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

	auto root = BuildTrieTree2(patterns);
	if (!root)
	{
		return;
	}

	BuildFail2(root);

	auto cur_base = root;
	for (int i = 0; i < m.size(); i++)
	{
		auto cur = cur_base->sons[GET_CHAR_INDEX(m[i])];
		while (cur != root)
		{
			if (cur->terminated_pattern_indexes.size())
			{
				for (int terminated_pattern_index : cur->terminated_pattern_indexes)
				{
					counts[terminated_pattern_index]++;
				}
			}
			cur = cur->fail;
		}

		cur_base = cur_base->sons[GET_CHAR_INDEX(m[i])];
	}

	for (int count : counts)
	{
		cout << count << endl;
	}
}