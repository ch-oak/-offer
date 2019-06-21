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
class Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		ListNode* res = NULL;
		ListNode* cur1 = pHead1, *cur2 = pHead2;
		int len1 = 0, len2 = 0;
		while (cur1) {
			cur1++;
			len1++;
		}
		while (cur2) {
			cur2++;
			len2++;
		}
		int off = abs(len2 - len1);
		cur1 = pHead1;
		cur2 = pHead2;
		if (len1 > len2) {
			while (off--)
				cur1++;
		}
		else
			while (off--)
				cur2++;
		while (cur1) {
			if (cur1->val == cur2->val) {
				res = cur1;
				break;
			}
			cur1++;
			cur2++;
		}
		return res;
	}
};

int main()
{

    std::cout << "Hello World!\n"; 
}

