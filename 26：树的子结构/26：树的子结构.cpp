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
		if (pRoot1==NULL || pRoot2==NULL)
			return false;
		//找到相同的根节点
		bool res = false;
		if (equal(pRoot1->val, pRoot2->val))
			res = isSame(pRoot1, pRoot2);
		if (!res)
			res = HasSubtree(pRoot1->left, pRoot2);
		if (!res)
			res = HasSubtree(pRoot1->right, pRoot2);
		return res;
	}
private:
	bool isSame(TreeNode* pRoot1, TreeNode* pRoot2) {//判断子结构是否相同
		if (pRoot2==NULL)
			return true;
		if (pRoot1==NULL)
			return false;
		if (!equal(pRoot1->val, pRoot2->val))
			return false;
		return isSame(pRoot1->left, pRoot2->left) && isSame(pRoot1->right, pRoot2->right);

	}
	bool equal(double num1, double num2) {
		if ((num1 - num2 > -0.00000001) && (num1 - num2 < 0.00000001))
			return true;
		else
			return false;
	}
};




int main()
{
	TreeNode* pRoot = new TreeNode(1);
	pRoot->left = new TreeNode(2);
	pRoot->right = new TreeNode(3);
	std::cout<<Solution().HasSubtree(pRoot,pRoot);
    std::cout << "Hello World!\n"; 
}

