// 面试题25：合并两个排序的链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

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
输入两个单调递增的链表，输出两个链表合成后的链表，
当然我们需要合成后的链表满足单调不减规则
*/
class Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* res = new ListNode(0);
		ListNode* head = res;
		while (pHead1&&pHead2) {//不停的把较小的节点加入结果链表
			if (pHead1->val <= pHead2->val) {
				res->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				res->next = pHead2;
				pHead2 = pHead2->next;
			}
			res = res->next;
		}
		res->next = pHead1 ? pHead1 : pHead2;
		return head->next;

	}
};

int main()
{
	ListNode* pHead1 = new ListNode(1);
	ListNode* pHead2 = new ListNode(2);
	auto res = Solution().Merge(pHead1, pHead2);
    std::cout << "Hello World!\n"; 
}

