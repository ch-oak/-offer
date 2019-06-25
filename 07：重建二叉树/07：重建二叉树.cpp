// 07：重建二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&tPage=1&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>


using namespace std;
//Definition for binary tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*
	输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
	例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回。
	*/
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		TreeNode* root = NULL;
		reConstructHelp(pre, vin, root, 0, pre.size() - 1, 0, vin.size() - 1);
		return root;
	}
private:
	void reConstructHelp(vector<int> &pre, vector<int> &vin,TreeNode* &root,int pre_start, int pre_end, int vin_start, int vin_end) {
		if (pre_start>pre_end || vin_start>vin_end)
			return;
		int root_val = pre[pre_start];
		root = new TreeNode(root_val);
		int mid;
		for (int i = vin_start; i <= vin_end; i++) {
			if (root_val == vin[i]) {
				mid = i;
				break;
			}
		}
		int left_len = mid - vin_start;
		if (left_len >= 0) {
			reConstructHelp(pre, vin, root->left, pre_start + 1, pre_start + left_len, vin_start, mid - 1);//重建左子树
			reConstructHelp(pre, vin, root->right, pre_start + left_len + 1, pre_end, mid + 1, vin_end);//重建右子树
		}
	}
};
int main()
{
	vector<int> pre{ 1,2,4,7,3,5,6,8 };
	vector<int> vin{ 4,7,2,1,5,3,8,6 };
	auto res = Solution().reConstructBinaryTree(pre, vin);
	std::cout << "Hello World!\n";
}