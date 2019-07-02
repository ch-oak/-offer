// 32：③之字形打印二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&tPage=3&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking

#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

/*
请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
*/
class Solution {
public:
	vector<vector<int> > Print(TreeNode* pRoot) {
		if (!pRoot)
			return {};
		vector<vector<int>> res;
		queue<TreeNode*> next{ {pRoot} };
		bool flag = true;
		while (!next.empty()) {
			vector<int> level;
			for (int i = next.size(); i > 0; i--) {
				auto temp = next.front();
				next.pop();
				level.push_back(temp->val);
				if (temp->left) next.push(temp->left);
				if (temp->right) next.push(temp->right);
			}
			if (flag) {//用一个标记符表示要不要逆序当前层
				res.push_back(level);
				flag = false;
			}
			else {
				reverse(level.begin(), level.end());
				res.push_back(level);
				flag = true;
			}
		}
		return res;
	}

};
int main()
{
    std::cout << "Hello World!\n"; 
}
