// 01：赋值运算符号函数.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//为行为类似指针的类增加赋值运算符函数

#include "pch.h"
#include <iostream>
class CMyString {
public:
	CMyString(char *data = NULL) :m_data(data) {}
	CMyString(const CMyString& str) { m_data = str.m_data; };
	~CMyString() { delete[] m_data; };
	CMyString& operator = (const CMyString &str) {//考虑防止复制，删除资源，申请资源。但是可能会出现异常
		if (this == &str)//防止自己复制自己
			return *this;
		delete[] m_data;//删除自己的资源

		m_data = new char[strlen(str.m_data) + 1];
		strcpy(m_data, str.m_data);
		return *this;
	}
private:
	char* m_data;
};

class CMyString {
public:
	CMyString(char *data = NULL) :m_data(data) {}
	CMyString(const CMyString& str) { m_data = str.m_data; };
	~CMyString() { delete[] m_data; };
	CMyString& operator = (const CMyString &str) {//针对可能出现异常的情况，使用临时变量交换指针，然后临时变量析构就不用我们清理资源了
		if (this != &str) {
			CMyString strtemp(str);
			char* pTemp = strtemp.m_data;
			strtemp.m_data = m_data;
			m_data = pTemp;
		}
		return *this;
	}
private:
	char* m_data;
};

int main()
{
    std::cout << "Hello World!\n"; 
}
