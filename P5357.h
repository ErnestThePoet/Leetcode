#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory>
#include <unordered_set>
#include <unordered_map>

using std::unordered_set;
using std::unordered_map;
using std::shared_ptr;
using std::make_shared;
using std::vector;
using std::queue;
using std::string;
using std::cin;
using std::cout;
using std::endl;

unordered_set<char> kCharSet;

struct TrieMapNode
{
	unordered_set<int> terminated_pattern_indexes;
	unordered_map<char, shared_ptr<TrieMapNode>> sons;
	shared_ptr<TrieMapNode> fail;

	TrieMapNode()
	{
		for (char c : kCharSet)
		{
			sons[c] = nullptr;
		}
	}
};

void InitCharSet()
{
	for (char c = 'a'; c <= 'z'; c++)
	{
		kCharSet.insert(c);
	}
}

shared_ptr<TrieMapNode> BuildTrieTree(const vector<string>& patterns)
{
	shared_ptr<TrieMapNode> root = make_shared<TrieMapNode>();

	for (int i = 0; i < patterns.size(); i++)
	{
		auto cur = root;
		for (int j = 0; j < patterns[i].size(); j++)
		{
			if (!cur->sons[patterns[i][j]])
			{
				cur->sons[patterns[i][j]] = make_shared<TrieMapNode>();
			}

			if (j == patterns[i].size() - 1)
			{
				cur->sons[patterns[i][j]]->terminated_pattern_indexes.insert(i);
			}

			cur = cur->sons[patterns[i][j]];
		}
	}

	return root;
}

void BuildFail(shared_ptr<TrieMapNode>& root)
{
	queue<shared_ptr<TrieMapNode>> q;

	root->fail = root;

	for (char c : kCharSet)
	{
		if (root->sons[c])
		{
			root->sons[c]->fail = root;
			q.push(root->sons[c]);
		}
		else
		{
			root->sons[c] = root;
		}
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (char c : kCharSet)
		{
			if (cur->sons[c])
			{
				cur->sons[c]->fail = cur->fail->sons[c];
				q.push(cur->sons[c]);
			}
			else
			{
				cur->sons[c] = cur->fail->sons[c];
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

	InitCharSet();
	auto root = BuildTrieTree(patterns);
	if (!root)
	{
		return;
	}

	BuildFail(root);

	auto cur_base = root;
	for (int i = 0; i < m.size(); i++)
	{
		auto cur = cur_base->sons[m[i]];
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

		cur_base = cur_base->sons[m[i]];
	}

	for (int count : counts)
	{
		cout << count << endl;
	}
}