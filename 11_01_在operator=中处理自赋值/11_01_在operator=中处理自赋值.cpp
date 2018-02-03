// 11_01_在operator=中处理自赋值.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#pragma region 能够处理自赋值，但是不具有异常安全性
class Bitmap
{

};

template <class T>
class Widget
{
public:
	Widget& operator=(const Widget &other)
	{
		if (this != &other) //处理自赋值
			return *this;
		delete[] _data;
		_data = new T[other._size];//如果在这里有一个new 抛出了异常，那么Widget就会持有一个指针指向一块被删除的内存区域(异常后系统会自动调用operator delete删除内存)，而这个时候原来的内存也已经被删除掉了
		memcpy(_data, other._data, _size * sizeof(T));
		_size = other._size;
		return *this;
	}
private:
	T *_data;
	int _size;
};


#pragma endregion

#pragma region 简单的修改使其具有异常安全性
template <class T>
class Widget1
{
public:
	Widget1& operator=(const Widget1 &other)
	{
		//这里去掉了自我赋值的检测的原因是:首先下面的代码能够处理自我赋值，这里加上自我赋值检测的话，也确实看上去效率会高一点(省去了一次内存分配等操作)
		//但是本身自我赋值发生的概率很小，增加自赋值检测会使代码变大并引入新的控制流分支，prefetching、caching和piplining等指令的效率都会降低。
		T *pOrig = _data;
		_data = new T[other._size];
		memcpy(_data, other._data, _size * sizeof(T));
		delete[]pOrig; //直到拷贝成功了才删掉原来的内存
		_size = other._size;
		return *this;
	}

private:
	T *_data;
	int _size;
};
#pragma endregion

#pragma region 更常见的做法，使用copy and swap技术

template <class T>
class Widget2
{
public:
	Widget2& operator=(const Widget2 &other)
	{
		Widget2  temp(other);  //创建临时对象，利用拷贝构造函数，这里具体的实现就是上面的拷贝赋值运算符差不多的实现
		swap(other); //
		return *this;
	}
	void swap(Widget2& other)
	{
		int temp = other._size;
		other._size = _size;
		_size = temp;

		T*tmp = other._data;
		other._data = _data;
		_data = tmp;
	}
private:
	T *_data;
	int _size;
};

#pragma endregion





int main()
{
	return 0;
}

