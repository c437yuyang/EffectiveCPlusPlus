// 49_01_new_handler.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <new>
#include <iostream>

//������һ�������Լ����new handler������

class NewHandlerHolder
{
public:
	explicit NewHandlerHolder(std::new_handler p) :handler(p) {}
	~NewHandlerHolder() { std::set_new_handler(handler); } //�����������е���set_new_handler���ָ���ǰ���õ�new_handler
private:
	std::new_handler handler;
	NewHandlerHolder(const NewHandlerHolder&); //��ֹ����
	NewHandlerHolder& operator=(const NewHandlerHolder&);
};

void outOfMem()
{
	std::cout << "out of memery" << std::endl;
	return;
}

//Ϊ�Լ������Ͷ������ʧ�ܵ�new-handler
class Widget //����д����static�����Ϳ�������ʵ
{
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc); //ȷ�������Լ���newhandler
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
	NewHandlerHolder(std::set_new_handler(currentHandler)); //�Ȱ�ϵͳ��global new_handler�ö���������
	//����std::new_handler ��ʵ�����滻��ȫ�ֵ�new_handler,���Ҫ�ö������ԭ����ȫ��new_handler���Լ����͵�����ɺ󣬽��лָ�
	return ::operator new(size); //����ȫ�ֺ���ִ���ڴ����
	//�������holder��������ָ���ȫ�ֵ�new handler
}

//����ķ�����ʵ��ͨ�õģ���˿�����һ��base class ��ʹ��ÿ���඼���Ծ߱���������
template<typename T>
class NewHandlerSupport
{
public:
	static std::new_handler set_new_handler(std::new_handler p) throw();
	static void* operator new(std::size_t size) throw(std::bad_alloc); //ȷ�������Լ���newhandler
private:
	static std::new_handler currentHandler;
	//�������ڲ���ȫû��ʹ��T������Ҳ����Ҫ������֮����Ҫ��ģ���������֣���Ϊ�˱�֤ÿ������ӵ���Լ���һ��currentHandler���ѡ�
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
	NewHandlerHolder(std::set_new_handler(currentHandler)); //�Ȱ�ϵͳ��global new_handler�ö���������
															//����std::new_handler ��ʵ�����滻��ȫ�ֵ�new_handler,���Ҫ�ö������ԭ����ȫ��new_handler���Լ����͵�����ɺ󣬽��лָ�
	return ::operator new(size); //����ȫ�ֺ���ִ���ڴ����
								 //�������holder��������ָ���ȫ�ֵ�new handler
}

//������һ�������ͣ�ֱ�Ӽ̳�һ�¼��ɡ�
class Widget1 :public NewHandlerSupport<Widget1>
{
	//��ӵ������Щ�����ˡ�
};


int main()
{

	//��������
	{
		std::set_new_handler(outOfMem);
		int *p = new int[0x7ffffff]; //������ģ��ʵ�֣�VSֱ�Ӿͱ�����
	}


	//�Զ�������
	{
		//�ͻ�ʹ�õ�����:
		Widget::set_new_handler(outOfMem); //�������Լ���ʧ�ܴ�����
		Widget *pw1 = new Widget; //����ڴ����ʧ�ܾ͵����Լ���OutOfMem����ɺ��ֻ�ָ�ȫ�ֵ�new_handler

		std::string *ps = new std::string; //���ǵ���ȫ�ֵ�new_handlers
		Widget::set_new_handler(0); //�趨ר����ΪNULL

		Widget*pw2 = new Widget; //�������ʧ���׳��쳣ֱ��


	}

	system("pause");
	return 0;
}



