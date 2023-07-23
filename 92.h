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
	ListNode* reverseBetween(ListNode* head, int left, int right)
	{
		ListNode root(0, head);

		const int move_count = right - left;

		ListNode* insertion_before = &root;

		for (int i = 1; i < left; i++)
		{
			insertion_before = insertion_before->next;
		}

		ListNode* fetch_before = insertion_before->next;

		for (int i = 0; i < move_count; i++)
		{
			ListNode* fetched = fetch_before->next;
			fetch_before->next = fetched->next;
			ListNode* insertion_next = insertion_before->next;
			insertion_before->next = fetched;
			fetched->next = insertion_next;
		}

		return root.next;
	}
};