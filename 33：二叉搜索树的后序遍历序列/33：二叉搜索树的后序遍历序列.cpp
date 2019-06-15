// 33：二叉搜索树的后序遍历序列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence) {
		if (sequence.empty())
			return false;
		int len = sequence.size();
		int root = sequence[len - 1];
		int i = 0;
		for (; i < len - 1; i++) {//root的左子树
			if (sequence[i] > root)
				break;
		}
		int j = i;
		for (; j < len - 1; j++) {//root的右子树中右没有小于根节点的数
			if (sequence[j] < root)
				return false;
		}
		bool left = true;
		if (i > 0) {//存在左子树
			vector<int> left_tree(sequence.begin(), sequence.begin() + i);//注意用迭代器初始化的时候是左闭右开
			left = VerifySquenceOfBST(left_tree);
		}
		bool right = true;
		if (i < len - 1) {//存在右子树
			vector<int> right_tree(sequence.begin()+i, sequence.begin()+(len-1));
			right = VerifySquenceOfBST(right_tree);
		}
		return left && right;

	}
};

int main()
{
	vector<int> s{5,7,6,9,11,10,8};
	cout << Solution().VerifySquenceOfBST(s) << endl;
    std::cout << "Hello World!\n"; 
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
