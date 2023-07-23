#pragma once

struct ListNode
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode root(0, head);

		ListNode* before_start = &root;
		while (before_start->next != nullptr)
		{
			int current_value = before_start->next->val;

			ListNode* end = before_start;

			while (end->next != nullptr && end->next->val == current_value)
			{
				end = end->next;
			}

			if (end != before_start->next)
			{
				before_start->next = end->next;
			}
			else
			{
				before_start = before_start->next;
			}
		}

		return root.next;
	}
};