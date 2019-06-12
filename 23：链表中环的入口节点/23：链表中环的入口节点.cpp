// 23：链表中环的入口节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>



struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		if (!pHead->next)
			return NULL;
		//先确定有没有环，并找到相遇节点
		ListNode *fast = pHead, *slow = pHead;
		while (fast->next->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (!fast || fast == slow)
				break;
		}
		if (!fast)
			return NULL;

		//确定环的长度
		ListNode* meet = slow;
		int len = 0;
		do {
			len++;
			slow = slow->next;
		} while (slow != meet);

		////快指针先走环的长度
		fast = pHead, slow = pHead;
		while (len--) {
			fast = fast->next;
		}
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}
		
		return slow;
	}
};

int main()
{
	ListNode* pHead = new ListNode(1);
	pHead->next = new ListNode(2);
	pHead->next->next = new ListNode(3);
	pHead->next->next->next = new ListNode(4);
	pHead->next->next->next->next = new ListNode(5);
	pHead->next->next->next->next->next = pHead->next->next;

	std::cout << Solution().EntryNodeOfLoop(pHead);

    std::cout << "Hello World!\n"; 
}


