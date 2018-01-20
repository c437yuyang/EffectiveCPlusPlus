// 47_01_��traitʵ��advance.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iterator>

//���յ�����������Ҫʵ�ֵ�����
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

//����Ҫʵ�֣�����trait_classes

// ���ȣ��Զ��������ṩһ��typedef iterator_category
template<class T>
class deque
{
public:
	class iterator
	{
	public:
		typedef random_access_iterator_tag iterator_category; //���������������<iterator>����ģ�Ϊ��˵���Ͳ���stl�������
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

//traits����ֱ����������ṩһ����Ӧ�Ķ��弴�� 
template<typename IterT>
struct iterator_traits
{
	typedef typename IterT::iterator_category iterator_category;
};

//Ϊ��֧������ָ�����ͣ��ṩһ��ƫ�ػ��汾
template <typename IterT>
struct iterator_traits<IterT*>
{
	typedef random_access_iterator_tag iterator_category;
};

//����advance
template<typename IterT, typename DistT>
void advance(IterT&iter, DistT d)
{
	if (typeid(typename::iterator_traits<IterT>::iterator_category) ==
		typeid(random_access_iterator_tag))
	{
		//��random access
	}
	else
		//....
}

//���������Ļ���������Ҫ������ʱ(typeid����)ȷ����if���ĸ���֧
//��˸ĳ���������ʵ�֣����ú�������ʵ�ֱ����ڵ�if����
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
// �������͵��������ơ�������

//����ֱ�ӵ���doAdvance��������
template<typename IterT, typename DistT>
void advance(IterT&iter, DistT d)
{
	doAdvance(iterT, d, iterator_traits<IterT>::iterator_category); //���������Զ��ж����ذ汾�ĵ��ã��Ӷ�ʵ�ֱ����ڵ�if
}



int main()
{
	return 0;
}

