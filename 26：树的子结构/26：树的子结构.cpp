// 26：树的子结构.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking

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
/*
输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
*/
/*
先找到根节点相同的点，再逐步比较。
*/
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
		if (pRoot2==NULL)//当pRoot2为空，说明前面都相同
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

