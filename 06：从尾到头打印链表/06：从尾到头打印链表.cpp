// 06：从尾到头打印链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
       int val;
       struct ListNode *next;
       ListNode(int x) :
             val(x), next(NULL) {
       }
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> res;
		if (!head)
			return res;
		helpPrint(head, res);
		return res;
	}
private:
	void helpPrint(ListNode* head,vector<int> &res) {
		if (head->next) {
			helpPrint(head->next, res);
		}
		res.push_back(head->val);
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}