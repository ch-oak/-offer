// 22：链表中倒数第k个节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

//双指针法，慢指针先指向开始，快指针指向第k个指针；然后同时前进，如果快指针为空，则慢指针指向即为所求。 
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
		int i = 0;
		ListNode* fast = pListHead, *slow = pListHead;
		for (; i < k; i++) {
			if (fast != NULL)
				fast = fast->next;
			else
				break;
		}
		if (i != k)
			return 0;
		while (fast) {
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
