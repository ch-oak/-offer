// 23：链表中环的入口节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

#include "pch.h"
#include <iostream>


//给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};

class Solution1 {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		//①先确定有没有环，并找到相遇节点
		ListNode *fast = pHead, *slow = pHead;
		while (fast&&fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast) break;//如果有环一定会相遇，因为进入环后移动一次，距离就减1，总能减到0
		}

		if (!fast || !fast->next)
			return NULL;

		//②计算环的长度
		int len = 0;
		do {
			len++;
			slow = slow->next;
		} while (slow != fast);
		slow = fast = pHead;

		//③快指针先走环的长度步，最后为在环的开始节点相遇
		while (len--)
			fast = fast->next;
		while (fast != slow) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};


//是否有环，环的起点，环的长度，两条链表是否有交点
class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		//①先确定有没有环，并找到相遇节点
		ListNode *fast = pHead, *slow = pHead;
		while (fast&&fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast) break;
		}
		if (!fast||!fast->next)
			return NULL;
		//②起点到环起点的距离 = 相遇节点到环的距离长度+环的长度的倍数
		slow = pHead;
		while (slow != fast) {
			slow = slow->next;
			fast = fast->next;
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


