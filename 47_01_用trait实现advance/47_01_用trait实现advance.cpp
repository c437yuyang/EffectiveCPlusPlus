// 47_01_用trait实现advance.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iterator>

//按照迭代器分类需要实现的样子
template<typename IterT, typename DistT>
void advance(IterT &iter, DistT &d)
{
	if (/*iter is a random access iterator*/)
	{
		iter += d;
	}
	else
	{
		if (d >= 0)
			while (d--) ++iter;
		else while (d++) --iter;
	}
}

//现在要实现，引入trait_classes

// 首先，自定义类型提供一个typedef iterator_category
template<class T>
class deque
{
public:
	class iterator
	{
	public:
		typedef random_access_iterator_tag iterator_category; //这个东西本身是在<iterator>里面的，为了说明就不用stl里面的了
	};
};
template<class T>
class list
{
public:
	class iterator
	{
	public:
		typedef bidirectional_iterator_tag iterator_category;
	};
};

//traits里面直接利用这个提供一个对应的定义即可 
template<typename IterT>
struct iterator_traits
{
	typedef typename IterT::iterator_category iterator_category;
};

//为了支持内置指针类型，提供一个偏特化版本
template <typename IterT>
struct iterator_traits<IterT*>
{
	typedef random_access_iterator_tag iterator_category;
};

//现在advance
template<typename IterT, typename DistT>
void advance(IterT&iter, DistT d)
{
	if (typeid(typename::iterator_traits<IterT>::iterator_category) ==
		typeid(random_access_iterator_tag))
	{
		//是random access
	}
	else
		//....
}

//但是这样的话，还是需要在运行时(typeid用了)确定走if的哪个分支
//因此改成下面这种实现，利用函数重载实现编译期的if功能
template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, random_access_iterator_tag tag)
{
	iter += d;
}

template<typename IterT, typename DistT>
void doAdvance(IterT& iter, DistT d, bidirectional_iterator_tag tag)
{
	if (d >= 0)
		while (d--)
			++iter;
	else
		while (d++)
			--iter;
}
// 其他类型迭代器类似。。。。

//现在直接调用doAdvance函数即可
template<typename IterT, typename DistT>
void advance(IterT&iter, DistT d)
{
	doAdvance(iterT, d, iterator_traits<IterT>::iterator_category); //编译器会自动判断重载版本的调用，从而实现编译期的if
}



int main()
{
	return 0;
}

