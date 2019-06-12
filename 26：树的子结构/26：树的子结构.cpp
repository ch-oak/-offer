// 26：树的子结构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (!pRoot2||!pRoot2)
			return false;
		if(pRoot1->val==pRoot2->val)
			return 
		
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}

