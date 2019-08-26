// 02：实现Singleton模式.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//单例模式：一个类只有一个实例，并提供一个访问实例的静态方法
//https://www.cnblogs.com/sunchaothu/p/10389842.html#c-%E5%AE%9E%E7%8E%B0%E5%8D%95%E4%BE%8B%E7%9A%84%E5%87%A0%E7%A7%8D%E6%96%B9%E5%BC%8F
//https://www.cnblogs.com/qiaoconglovelife/p/5851163.html

//为什么类的静态成员变量要再类外初始化？
/*
1. 在类中，只是声明了静态变量，并没有定义。 
2. 声明只是表明了变量的数据类型和属性，并不分配内存；定义则是需要分配内存的。
注意：如果在类里面这么写int a; 那么是既声明了变量，也定义了变量，两者合在一起了。
3. 静态成员是“类级别”的，也就是它和类的地位等同，而普通成员是“对象（实例）级别”的。类级别的成员，
先于该类任何对象的存在而存在，它被该类所有的对象共享。
4. 现在，咱们假定要实例化该类的一个对象，那么会发生什么事情呢？静态成员肯定要出现在这个对象里面的，对吧？
这时候才去定义那个静态成员吗？这显然是不合适的。因为，比如有另外一个线程也要创建该类的对象，那么也要按照
这个方式去定义那个静态成员。这会产生两种可能的情况：1. 重复定义；2. 就算不产生重复定义的情况，也会产生竞争
，从而造成死锁的问题，以至于对象无法创建。很显然，编译器不能这么干。那么很合理的解决办法，就是事先在类的外
部把它定义好，然后再供所有的对象共享。 注意：类的静态常量成员可以类内初始化。
*/

#include "pch.h"
#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

//懒汉式，用到才创建实例
class Singleton{//线程不安全，内存泄漏
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;//禁止拷贝
	Singleton& operator=(const Singleton&) = delete;//禁止复制

	static Singleton* m_instance;

public:
	static Singleton* getInstance() {
		if (m_instance == NULL)
			m_instance = new Singleton;//静态成员只能访问静态成员，所以指针必须是静态的。
		return m_instance;
	}		
};

Singleton* Singleton::m_instance = nullptr;


class Singleton {//使用互斥量mutex和共享指针
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;//禁止拷贝
	Singleton& operator=(const Singleton&) = delete;//禁止复制

	static Singleton* m_instance;
	static mutex m_mutex;

public:
	static shared_ptr<Singleton> getInstance() {
		if (m_instance == NULL) {//空才加锁，防止资源浪费,双检锁机制
			lock_guard<mutex> lk(m_mutex);
			if (m_instance == NULL)
				m_instance = new Singleton();
		}
		return m_instance;
	}


};
Singleton* Singleton::m_instance = nullptr;
mutex Singleton::m_mutex;


class Singleton {//使用局部静态变量
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;//禁止拷贝
	Singleton& operator=(const Singleton&) = delete;//禁止复制

public:
	static Singleton& getInstance() {
		static Singleton instance;
		return instance;
	}
}

//饿汉式，使用静态成员变量直接创建
class Singleton {
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;//禁止拷贝
	Singleton& operator=(const Singleton&) = delete;//禁止复制

	static Singleton* m_instance;

public:
	static Singleton* getInstance() {
		
		return m_instance;
	}
};

Singleton* Singleton::instance = new Singleton();

int main()
{
    std::cout << "Hello World!\n"; 
}
