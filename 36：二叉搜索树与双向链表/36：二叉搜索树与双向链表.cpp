// 36：二叉搜索树与双向链表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
	TreeNode* Convert(TreeNode* pRootOfTree)
	{
		TreeNode* last = NULL;
		Convert(pRootOfTree, last);
		while (last&&last->left)
			last = last->left;
		return last;
	}
public:
	void Convert(TreeNode* cur, TreeNode* &last) {
		if (!cur)
			return;
		if (cur->left)
			Convert(cur->left, last);
		
		//连接上一个节点与当前节点，并更新上一个节点为当前节点
		cur->left = last;
		if (last)
			last->right = cur;
		last = cur;

		if (cur->right)
			Convert(cur->right, last);
	}
};

int main()
{
	TreeNode* cur = new TreeNode(2);
	cur->left = new TreeNode(1);
	cur->right = new TreeNode(3);
	Solution().Convert(cur);
    std::cout << "Hello World!\n"; 
}
