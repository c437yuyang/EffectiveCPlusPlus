// 38_ModelSetThroughIsImplementedInTermsOf.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <list>
#include <iterator>


//����ʵ�ֵ�set��ʵҲ��һ��unordered_set��û�������ǰ��ղ���˳��洢��
template<class T>
class Set {
public:
	bool member(const T& item) const; //ע�⣬ֻ��const T& û�� const& T ������û��������
	void insert(const T& item);
	void remove(const T& item);
	std::size_t size() const;
	void output(ostream& out) const;
private:
	std::list<T> rep; //ͨ��listʵ��Set,IsImplementedInTermsOf
};

template<class T>
bool Set<T>::member(const T& item) const
{
	return std::find(rep.begin(), rep.end(), item) != rep.end();
}

template<class T>
void Set<T>::insert(const T& item)
{
	if (!member(item)) rep.push_back(item);
}

template<class T>
void Set<T>::remove(const T& item)
{
	if (member(item)) rep.remove(item);
}

template<class T>
std::size_t Set<T>::size() const 
{
	return rep.size();
}

template<class T>
void Set<T>::output(ostream & out) const
{
	std::copy(rep.begin(), rep.end(), ostream_iterator<T>(out, " "));
}

template<class T> //ͬһ�����ռ����ṩ�ǳ�Ա�������ó�Ա����
ostream & operator<<(ostream & out,Set<T> &rep)
{
	rep.output(out);
	return out;
}

template <class T>
class Widget
{
public:
	Widget();
	~Widget();
	void printInfo();
	void printInfo(T value);
	void printInfo1(const T& value) const;
private:

};

template<class T>
Widget<T>::Widget()
{
}

template<class T>
Widget<T>::~Widget()
{
}

template<class T>
void Widget<T>::printInfo()
{
	cout << endl;
}

template<class T>
void Widget<T>::printInfo(T value)
{
	cout << value <<endl;
}

template<class T>
void Widget<T>::printInfo1(const T& value) const
{
	cout << value << endl;
}

int main()
{
	Set<int> iset;
	iset.insert(1);
	iset.insert(1);
	iset.insert(2);
	iset.insert(3);
	std::cout << iset.member(1) << std::endl;
	std::cout << iset << std::endl;


	system("pause");
	return 0;
}

