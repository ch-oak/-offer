// 08：二叉树的下一个节点.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>


using namespace std;
struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
	}
};

class Solution {
public:
	/*
	给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
	注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
	*/
	TreeLinkNode* GetNext(TreeLinkNode* pNode)
	{
		if (!pNode)
			return NULL;
		TreeLinkNode* res = NULL;
		if (pNode->right) {//有右子树，下一个节点为右子树最左边的节点
			TreeLinkNode* temp = pNode->right;
			while (temp->left)
				temp = temp->left;
			res = temp;
		}
		else if (pNode->next) {//无右子树，当前节点某一祖先为其父节点的左子树，该祖先父亲即为所求
			auto cur = pNode;
			auto parent = pNode->next;
			while (parent&&cur == parent->right) {
				cur = parent;
				parent = parent->next;
			}
			res = parent;
		}
		return res;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}
