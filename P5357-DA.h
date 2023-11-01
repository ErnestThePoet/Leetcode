#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using std::vector;
using std::queue;
using std::string;
using std::pair;
using std::cin;
using std::cout;
using std::endl;

constexpr int kRootState = 0;
constexpr int kRootStateInitialBase = 1;
constexpr int kFreeBase = 0;

vector<char> kCharSet;
vector<int> kCharCodeSet;

template<typename T>
class OnDemandVector
{
	vector<T> base_;

	void EnsureSizeForIndex(const size_t index)
	{
		if (index >= base_.size())
		{
			base_.resize(index + 1);
		}
	}

public:
	OnDemandVector() = default;
	OnDemandVector(const size_t size) :base_(size) {}
	OnDemandVector(const size_t size, const T& value) :base_(size, value) {}

	~OnDemandVector() = default;

	OnDemandVector(const OnDemandVector<T>& right) :base_(right.base_) {}
	OnDemandVector(OnDemandVector<T>&& right) noexcept :base_(std::move(right.base_)) {}

	OnDemandVector<T>& operator=(const OnDemandVector<T>& right)
	{
		if (this == &right)
		{
			return *this;
		}

		base_ = right.base_;
		return *this;
	}

	OnDemandVector<T>& operator=(OnDemandVector<T>&& right) noexcept
	{
		if (this == &right)
		{
			return *this;
		}

		base_ = std::move(right.base_);
		return *this;
	}

	T& operator[](const size_t index) noexcept
	{
		EnsureSizeForIndex(index);
		return base_[index];
	}

	size_t size() const
	{
		return base_.size();
	}
};

struct CheckNode
{
	int parent_state;
	int fail_state;
	vector<int> outputs;

	CheckNode() :parent_state(kRootState), fail_state(kRootState) {}
};

inline int GetCharCode(const char c)
{
	// Currently Only supports lower alpha
	if (islower(c))
	{
		return c - 'a';
	}

	return -1;
}

void InitCharSetAndCharCodeSet()
{
	// Currently Only supports lower alpha
	for (int c = 'a'; c <= 'z'; c++)
	{
		kCharSet.push_back(c);
		kCharCodeSet.push_back(GetCharCode(c));
	}
}

inline bool HasTransition(OnDemandVector<int>& base,
	OnDemandVector<CheckNode>& check,
	const int parent_state,
	const int new_state)
{
	return base[new_state] != kFreeBase &&
		check[new_state].parent_state == parent_state;
}

pair<OnDemandVector<int>, OnDemandVector<CheckNode>> BuildDoubleArray(const vector<string>& patterns)
{
	const int kInitialSize = patterns.size() * 20;

	OnDemandVector<int> base(kInitialSize);
	OnDemandVector<CheckNode> check(kInitialSize);

	int parent_state = kRootState;
	base[kRootState] = kRootStateInitialBase;

	for (int i = 0; i < patterns.size(); i++)
	{
		parent_state = kRootState;
		for (int j = 0; j < patterns[i].size(); j++)
		{
			int new_state = base[parent_state] + GetCharCode(patterns[i][j]);
			// If new_state is empty, then base[new_state]!=kFreeBase.
			// If there is a previous transition from parent_state to new_state, 
			// then base[new_state]!=kFreeBase and check[new_state].parent_state==parent_state.
			// If there is a previous transition from another state to new_state, 
			// then base[new_state]!=kFreeBase and check[new_state].parent_state!=parent_state.
			if (base[new_state] != kFreeBase && check[new_state].parent_state != parent_state)
			{
				const int old_parent_base = base[parent_state];
				// Find all children char codes
				vector<int> children_char_codes;
				for (const int char_code : kCharCodeSet)
				{
					const int cur_state = old_parent_base + char_code;
					if (base[cur_state] != kFreeBase && check[cur_state].parent_state == parent_state)
					{
						children_char_codes.push_back(char_code);
					}
				}

				// Find a new parent state base with linear search
				int new_parent_base = old_parent_base + 1;
				while (true)
				{
					bool ok = base[new_parent_base + GetCharCode(patterns[i][j])] == kFreeBase;

					if (ok)
					{
						for (const int char_code : children_char_codes)
						{
							if (base[new_parent_base + char_code] != kFreeBase)
							{
								ok = false;
								break;
							}
						}
					}

					if (ok)
					{
						break;
					}

					new_parent_base++;
				}

				// Base relocate algorithm
				for (const int child_char_code : children_char_codes)
				{
					const int old_child_state = old_parent_base + child_char_code;
					const int new_child_state = new_parent_base + child_char_code;

					check[new_child_state] = check[old_child_state];

					base[new_child_state] = base[old_child_state];

					// As state values of these children have changed, check.parent_state 
					// should also be updated for children of these children.
					for (const int char_code : kCharCodeSet)
					{
						const int cur_grandchild_state = base[old_child_state] + char_code;
						if (base[cur_grandchild_state] != kFreeBase &&
							check[cur_grandchild_state].parent_state == old_child_state)
						{
							check[cur_grandchild_state].parent_state = new_child_state;
						}
					}

					check[old_child_state] = CheckNode();
					base[old_child_state] = kFreeBase;
				}

				base[parent_state] = new_parent_base;
				new_state = new_parent_base + GetCharCode(patterns[i][j]);
			}

			if (base[new_state] == kFreeBase)
			{
				// Inherit base
				base[new_state] = base[parent_state];

				check[new_state].parent_state = parent_state;
			}

			if (j == patterns[i].size() - 1)
			{
				check[new_state].outputs.push_back(i);
			}

			parent_state = new_state;
		}
	}

	return { std::move(base),std::move(check) };
}

void BuildFail(OnDemandVector<int>& base, OnDemandVector<CheckNode>& check)
{
	queue<int> q;

	for (const int char_code : kCharCodeSet)
	{
		// As root state's base may also have been relocated,
		// we must not use kRootStateInitialBase
		const int cur_state = base[kRootState] + char_code;
		if (base[cur_state] != kFreeBase &&
			check[cur_state].parent_state == kRootState)
		{
			check[cur_state].fail_state = kRootState;
			q.push(cur_state);
		}
	}

	while (!q.empty())
	{
		const int parent_state = q.front();
		q.pop();

		for (const int char_code : kCharCodeSet)
		{
			const int cur_state = base[parent_state] + char_code;
			if (HasTransition(base, check, parent_state, cur_state))
			{
				int fail_parent_state = check[parent_state].fail_state;
				int fail_state = base[fail_parent_state] + char_code;
				while (fail_parent_state != kRootState &&
					!HasTransition(base, check, fail_parent_state, fail_state))
				{
					fail_parent_state = check[fail_parent_state].fail_state;
					fail_state = base[fail_parent_state] + char_code;
				}

				if (fail_parent_state == kRootState &&
					!HasTransition(base, check, fail_parent_state, fail_state))
				{
					fail_state = kRootState;
				}

				check[cur_state].fail_state = fail_state;

				q.push(cur_state);
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

	InitCharSetAndCharCodeSet();
	auto double_array = BuildDoubleArray(patterns);
	auto base = std::move(double_array.first);
	auto check = std::move(double_array.second);

	BuildFail(base, check);

	int base_state = kRootState;
	for (int i = 0; i < m.size(); i++)
	{
		const int char_code = GetCharCode(m[i]);
		int parent_state = base_state;
		int cur_state = base[base_state] + char_code;

		while (parent_state != kRootState &&
			!HasTransition(base, check, parent_state, cur_state))
		{
			parent_state = check[parent_state].fail_state;
			cur_state = base[parent_state] + char_code;
		}

		if (parent_state == kRootState && !HasTransition(base, check, parent_state, cur_state))
		{
			cur_state = kRootState;
		}

		base_state = cur_state;

		while (cur_state != kRootState)
		{
			for (const int output : check[cur_state].outputs)
			{
				counts[output]++;
			}

			cur_state = check[cur_state].fail_state;
		}
	}

	for (int count : counts)
	{
		cout << count << endl;
	}
}