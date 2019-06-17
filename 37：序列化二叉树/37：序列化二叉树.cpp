// 37：序列化二叉树.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


/*请实现两个函数，分别用来序列化和反序列化二叉树*/



#include "pch.h"
#include <iostream>
#include <sstream>
#include <string>

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
 1. 对于序列化：使用前序遍历，递归的将二叉树的值转化为字符，并且在每次二叉树的结点
不为空时，在转化val所得的字符之后添加一个' ， '作为分割。对于空节点则以 '$' 代替。
 2. 对于反序列化：按照前序顺序，递归的使用字符串中的字符创建一个二叉树(特别注意：
在递归时，递归函数的参数一定要是char ** ，这样才能保证每次递归后指向字符串的指针会
随着递归的进行而移动！！！)
*/

class Solution {
public:
	char* Serialize(TreeNode *root) {
		if (!root)
			return NULL;
		string str;
		Serialize(root, str);
		char* res = new char[str.size() + 1];
		for (int i = 0; i < str.size(); i++)
			res[i] = str[i];
		res[str.size()] = '\0';
		cout << res << endl;
		return res;

	}
	TreeNode* Deserialize(char *str) {
		if (!str)
			return NULL;

		TreeNode* res = Deserialize(&str);
		return res;
	}
private:
	void Serialize(TreeNode* root, string &str) {
		if (!root) {
			str += '$';
			return;
		}
		str += to_string(root->val);
		str += ',';
		Serialize(root->left, str);
		Serialize(root->right, str);
	}

	TreeNode* Deserialize(char** str) {
		if (**str == '$') {
			++(*str);
			return NULL;
		}
		int num = 0;
		while (**str >= '0'&&**str <= '9') {
			num = 10 * num + (**str - '0');
			++(*str);
		}
		TreeNode* root = new TreeNode(num);
		if (**str == '\0')
			return root;
		else
			++(*str);
		root->left = Deserialize(str);
		root->right = Deserialize(str);
		return root;
	}
};

int main()
{
	TreeNode* root = new TreeNode(8);
	root->left = new TreeNode(6);
	root->right = new TreeNode(10);
	root->left->left = new TreeNode(5);
	root->left->right = new TreeNode(7);
	root->right->left = new TreeNode(9);
	root->right->right = new TreeNode(11);
	
	Solution().Deserialize(Solution().Serialize(root));
	const char *c = "test";
	string res = c;
	string str;
	str += 12;
	str += to_string(12);
    std::cout << "Hello World!\n"; 
}
