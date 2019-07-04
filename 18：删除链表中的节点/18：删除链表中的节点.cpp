// 18：删除链表中的节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/623a5ac0ea5b4e5f95552655361ae0a8?tpId=13&tqId=11203&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
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

/*
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，
返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/
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
			else {//如果有相同节点
				int val = cur->val;
				ListNode* del = cur;
				while (del && del->val == val) {
					next = del->next;
					delete del;
					del = next;
				}
				if (!pre)
					pHead = next;//一开始就有重复
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

