// 52：两个链表中的第一个公共节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
/*
找出两个链表的长度差a，长的链表先走a步
*/
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode* res = NULL;
		ListNode* cur1 = pHead1, *cur2 = pHead2;
		int len1 = 0, len2 = 0;
		while (cur1) {
			cur1 = cur1->next;
			len1++;
		}
		while (cur2) {
			cur2 = cur2->next;
			len2++;
		}
		int off = abs(len2 - len1);
		cur1 = pHead1;
		cur2 = pHead2;
		if (len1 > len2) {
			while (off--)
				cur1 = cur1->next;
		}
		else
			while (off--)
				cur2 = cur2->next;
		while (cur1) {
			if (cur1 == cur2) {
				res = cur1;
				break;
			}
			cur1 = cur1->next;
			cur2 = cur2->next;
		}
		return res;
	}
};

int main()
{
	ListNode* pHead1 = new ListNode(1);
	ListNode* pHead2 = new ListNode(2);
	pHead1->next = new ListNode(3);
	pHead2->next = new ListNode(4);
	pHead1->next->next = pHead2->next;

	auto res = Solution().FindFirstCommonNode(pHead1, pHead2);
    std::cout << "Hello World!\n"; 
}

