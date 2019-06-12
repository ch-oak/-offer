// 22：链表中倒数第k个节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//双指针法，快指针先走k-1步，慢指针开始走，快指针走到终点时， 
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		ListNode* fast = pListHead, *slow = pListHead;
		if (k == 0)
			return 0;
		if (pListHead == NULL)
			return 0;
		for (unsigned int i = 0; i < k - 1; i++) {
			if (fast->next)
				fast = fast->next;
			else
				return;
		}
		while (fast->next) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;

	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
