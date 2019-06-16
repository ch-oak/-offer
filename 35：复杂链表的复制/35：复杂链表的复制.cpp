// 35：复杂链表的复制.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*
*输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，
*(另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。
*（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/


#include "pch.h"
#include <iostream>
#include <map>

using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
			label(x), next(NULL), random(NULL) {
	}
};

class Solution {
public:
	RandomListNode* Clone(RandomListNode* pHead)
	{
		RandomListNode* pRes = new RandomListNode(0);
		bool flag = true;
		RandomListNode* cur = pHead;
		RandomListNode* preCopy = pRes;
		RandomListNode* curCopy;
		map<RandomListNode*, RandomListNode*> note;
		while (cur) {
			curCopy = new RandomListNode(cur->label);
			preCopy->next = curCopy;
			preCopy = curCopy;
			note[cur] = curCopy;

			cur = cur->next;
		}
		curCopy = pRes->next;
		cur = pHead;
		while (curCopy) {
			if(cur->random)
				curCopy->random = note[cur->random];
			curCopy = curCopy->next;
			cur = cur->next;
		}
		auto res = pRes->next;
		delete pRes;
		return res;
	}
};



int main()
{
	RandomListNode* temp = new RandomListNode(0);
	Solution().Clone(temp);
    std::cout << "Hello World!\n"; 
}
