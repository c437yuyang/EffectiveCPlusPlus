// 11_01_��operator=�д����Ը�ֵ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#pragma region �ܹ������Ը�ֵ�����ǲ������쳣��ȫ��
class Bitmap
{

};

template <class T>
class Widget
{
public:
	Widget& operator=(const Widget &other)
	{
		if (this != &other) //�����Ը�ֵ
			return *this;
		delete[] _data;
		_data = new T[other._size];//�����������һ��new �׳����쳣����ôWidget�ͻ����һ��ָ��ָ��һ�鱻ɾ�����ڴ�����(�쳣��ϵͳ���Զ�����operator deleteɾ���ڴ�)�������ʱ��ԭ�����ڴ�Ҳ�Ѿ���ɾ������
		memcpy(_data, other._data, _size * sizeof(T));
		_size = other._size;
		return *this;
	}
private:
	T *_data;
	int _size;
};


#pragma endregion

#pragma region �򵥵��޸�ʹ������쳣��ȫ��
template <class T>
class Widget1
{
public:
	Widget1& operator=(const Widget1 &other)
	{
		//����ȥ�������Ҹ�ֵ�ļ���ԭ����:��������Ĵ����ܹ��������Ҹ�ֵ������������Ҹ�ֵ���Ļ���Ҳȷʵ����ȥЧ�ʻ��һ��(ʡȥ��һ���ڴ����Ȳ���)
		//���Ǳ������Ҹ�ֵ�����ĸ��ʺ�С�������Ը�ֵ����ʹ�����������µĿ�������֧��prefetching��caching��piplining��ָ���Ч�ʶ��ή�͡�
		T *pOrig = _data;
		_data = new T[other._size];
		memcpy(_data, other._data, _size * sizeof(T));
		delete[]pOrig; //ֱ�������ɹ��˲�ɾ��ԭ�����ڴ�
		_size = other._size;
		return *this;
	}

private:
	T *_data;
	int _size;
};
#pragma endregion

#pragma region ��������������ʹ��copy and swap����

template <class T>
class Widget2
{
public:
	Widget2& operator=(const Widget2 &other)
	{
		Widget2  temp(other);  //������ʱ�������ÿ������캯������������ʵ�־�������Ŀ�����ֵ���������ʵ��
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

