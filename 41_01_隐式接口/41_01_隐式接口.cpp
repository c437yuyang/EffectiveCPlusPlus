// 41_01_��ʽ�ӿ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class Widget 
{
public:
	Widget();
	virtual ~Widget();
	virtual std::size_t size() const;
	virtual void normalize();
	bool operator!=(const Widget& rhs) { return this->id != rhs.id; }

private:
	int id;
};

void doProcessing(Widget &w)  //�����Ķ�̬�ͽӿڣ������ڶ�̬
{
	Widget w1;
	if (w.size() > 10 && w != w1) 
	{
		
	}
}

template<class T> //��ʽ�ӿ�
void doProcessing1(T& w)
{
	Widget w1;
	if (w.size() > 10 && w != w1) 
	{
		T temp(w);
		w.normalize();
	}
}
int main()
{
	//doProcessing1(1); //����û�а취����size�� !=w1
	Widget w;
	doProcessing1(w); //�����������ڼ�Ķ�̬,ֻҪ��������(w.size() > 10 && w != w1)�Ǹ�bool���ʽ�Ϳ�����
	//��֮�������ľ���:
	//����ȥ����doProcessing1���������Ҫ�����ͱ���֧��:
	//(1)size(2)operator!=(3)copy ctor(4)normalize
	//���Ƕ���	if (w.size() > 10 && w != w1) ���������˵������Ҫ��Щ������ֻ��Ҫ�����Ǹ�bool���ʽ���ɡ�
	//��Ϊsize()���ԴӼ̳л�ã�operator>10Ҳ����ֻҪ����T������ʽת�ͳ�10������(������int)���ɣ�����Ĳ�����Ҳ��һ���ģ�ֻҪ�ܹ���ʽת�ͳɲ���ʽ�ұߵ����ͼ��ɡ�
	system("pause");
    return 0;
}

