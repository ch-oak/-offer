// 面试题25：合并两个排序的链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		ListNode* res = new ListNode(0);
		ListNode* cur = res;
		if (!pHead1)
			return pHead2;
		if (!pHead2)
			return pHead1;
		while (pHead1 && pHead2) {
			if (pHead1->val <= pHead2->val) {
				cur->next = pHead1;
				pHead1 = pHead1->next;
			}
			else {
				cur->next = pHead2;
				pHead2 = pHead2->next;
			}
			cur = cur->next;
		}
		cur->next = pHead1 ? pHead1 : pHead2;
		cur = res->next;
		delete res;
		return cur;
		
	}
};

int main()
{
	ListNode* pHead1 = new ListNode(1);
	ListNode* pHead2 = new ListNode(2);
	auto res = Solution().Merge(pHead1, pHead2);
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
