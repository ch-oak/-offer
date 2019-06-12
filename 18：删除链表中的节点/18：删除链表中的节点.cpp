// 18：删除链表中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//①在O(1)时间内删除链表中的节点
//②删除链表中重复的节点

#include "pch.h"
#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode* next;
	ListNode(int val) :val(val), next(NULL) {};
};

//直接用下一个节点要删除的节点，并删除下一个节点
class Solution1 {
	void deleteNode(ListNode** head, ListNode* toBeDelete) {
		if (toBeDelete->next != NULL) {//删除节点不是尾节点
			toBeDelete->val = toBeDelete->next->val;
			ListNode* temp = toBeDelete->next;
			toBeDelete->next = toBeDelete->next->next;
			delete temp;
			temp = NULL;
		}
		else if (toBeDelete == *head) {//只有一个节点
			delete toBeDelete;
			toBeDelete = NULL;
			*head = NULL;
		}
		else {//有多个节点，删除节点是尾点
			ListNode* node = *head;
			while (node->next != toBeDelete)
				node = node->next;
			delete toBeDelete;
			toBeDelete = NULL;
			node->next = NULL;
		}
	}
};

//删除重复的节点，不保留重复的节点
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		ListNode* pre = NULL;
		ListNode* cur = pHead;
		if (!pHead)
			return pHead;
		while (cur!=NULL) {
			ListNode* next = cur->next;
			bool flag = false;
			if (next&&next->val == cur->val)
				flag = true;
			if (!flag) {
				pre = cur;
				cur = cur->next;
			}
			else {
				int val = cur->val;
				ListNode* del = cur;
				while (del && del->val == val) {
					next = del->next;
					delete del;
					del = next;
				}
				if (!pre)
					pHead = next;
				else {
					pre->next = next;//连接
				}
				cur = next;
			}
		}
		return pHead;
	}
};


int main()
{
	ListNode* pHead = new ListNode(1);
	pHead->next = new ListNode(2);
	ListNode* temp = pHead->next;
	temp->next = new ListNode(2);
	Solution().deleteDuplication(pHead);
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
