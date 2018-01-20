// 49_01_new_handler.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <new>
#include <iostream>

//下面是一个定制自己类的new handler的例子

class NewHandlerHolder
{
public:
	explicit NewHandlerHolder(std::new_handler p) :handler(p) {}
	~NewHandlerHolder() { std::set_new_handler(handler); } //在析构函数中调用set_new_handler来恢复先前设置的new_handler
private:
	std::new_handler handler;
	NewHandlerHolder(const NewHandlerHolder&); //禁止拷贝
	NewHandlerHolder& operator=(const NewHandlerHolder&);
};

void outOfMem()
{
	std::cout << "out of memery" << std::endl;
	return;
}

//为自己的类型定义分配失败的new-handler
class Widget //就是写两个static函数就可以了其实
{
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc); //确保调用自己的newhandler
private:
	static std::new_handler currentHandler;
};

std::new_handler Widget::currentHandler = NULL;
std::new_handler Widget::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

void * Widget::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder(std::set_new_handler(currentHandler)); //先把系统的global new_handler用对象来管理
	//设置std::new_handler 其实就是替换了全局的new_handler,因此要用对象管理原来的全局new_handler，自己类型调用完成后，进行恢复
	return ::operator new(size); //调用全局函数执行内存分配
	//结束后会holder类析构会恢复成全局的new handler
}

//上面的方法其实是通用的，因此可以用一个base class 来使得每个类都可以具备这种能力
template<typename T>
class NewHandlerSupport
{
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc); //确保调用自己的newhandler
private:
	static std::new_handler currentHandler;
	//这个类的内部完全没有使用T，但是也不需要，这里之所以要用模板类来区分，是为了保证每个类型拥有自己的一份currentHandler而已。
};

template<typename T>
std::new_handler NewHandlerSupport<T>::currentHandler = NULL;

template<typename T>
std::new_handler NewHandlerSupport<T>::set_new_handler(std::new_handler p) throw()
{
	std::new_handler oldHandler = currentHandler;
	currentHandler = p;
	return oldHandler;
}

template<typename T>
void * NewHandlerSupport<T>::operator new(std::size_t size) throw(std::bad_alloc)
{
	NewHandlerHolder(std::set_new_handler(currentHandler)); //先把系统的global new_handler用对象来管理
															//设置std::new_handler 其实就是替换了全局的new_handler,因此要用对象管理原来的全局new_handler，自己类型调用完成后，进行恢复
	return ::operator new(size); //调用全局函数执行内存分配
								 //结束后会holder类析构会恢复成全局的new handler
}

//现在来一个新类型，直接继承一下即可。
class Widget1 :public NewHandlerSupport<Widget1>
{
	//就拥有了那些能力了。
};


int main()
{

	//内置类型
	{
		std::set_new_handler(outOfMem);
		int *p = new int[0x7ffffff]; //并不能模拟实现，VS直接就报错了
	}


	//自定义类型
	{
		//客户使用的例子:
		Widget::set_new_handler(outOfMem); //先设置自己的失败处理函数
		Widget *pw1 = new Widget; //如果内存分配失败就调用自己的OutOfMem，完成后，又会恢复全局的new_handler

		std::string *ps = new std::string; //还是调用全局的new_handlers
		Widget::set_new_handler(0); //设定专属的为NULL

		Widget*pw2 = new Widget; //如果分配失败抛出异常直接


	}

	system("pause");
	return 0;
}



