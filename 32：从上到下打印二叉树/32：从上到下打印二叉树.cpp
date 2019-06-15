// 32：从上到下打印二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
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
class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		if (!root)
			return res;
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {//利用队列先进先出的性质，保存子节点
			auto temp = q.front();
			res.push_back(temp->val);
			q.pop();
			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
		return res;
	}
};


class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root)
			return {};
		queue<TreeNode*> next{ {root} };
		vector<vector<int>> res;
		while (!next.empty()) {
			vector<int> level;
			for (int i = next.size(); i > 0; i--) {//保存当前层
				TreeNode* front = next.front();
				next.pop();
				level.push_back(front->val);
				if (front->left) next.push(front->left);
				if (front->right) next.push(front->right);
			}
			res.push_back(level);
		}

		return res;
	}
};

int main()
{
    std::cout << "Hello World!\n"; 
}


