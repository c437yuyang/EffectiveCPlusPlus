// 14_01_��Դ�������copying��Ϊ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <memory>
class Mutex;
void lock(Mutex*);
void unlock(Mutex*);

//���������ʵ�ֶ���mutex�Ĺ����Ǽ����ͽ������ﲻ������ȥ
class Lock
{
public:
	explicit Lock(Mutex* pm):mutexPtr(pm)
	{
		lock(mutexPtr);
	}
	~Lock()
	{
		unlock(mutexPtr);
	}
private:
	Mutex *mutexPtr;
};

//����������RAII�࣬�����Ƶ�ʱ������Ͳ�����
//�����������������һ��:
//1.��ֹ���ƣ�private�̳���uncopyable���ɡ�
//2.�Եײ���Դʹ�����ü���,��˰�mutex* �ĳ� shared_ptr<Mutex>���ɣ��ٶ���һ��ɾ����(auto_ptr���ܶ���ɾ��������Զ����delete����)���������unlock���ɡ�
//��ʱ�Ĵ���:
class Lock
{
public:
	explicit Lock(Mutex* pm) :mutexPtr(pm,unlock) //���ﴫ��ɾ�������й���
	{
		lock(mutexPtr.get());
	}
	//ȥ������������
private:
	std::shared_ptr<Mutex> mutexPtr;
};

//3.���Ƶײ���Դ��Ҳ�����������ʱ�Լ���дcopying�������ɡ�
//4.ת�Ƶײ���Դ��ӵ��Ȩ����ʱʹ��auto_ptr���ɡ�


int main()
{
    return 0;
}

