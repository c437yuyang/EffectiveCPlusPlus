#pragma once
//�ο���stlԴ������3.2 P81

//���캯��()
//��������
//operator=()
//�������캯��
//opertor*
//operator->
//get()
//release()
namespace YXP_Utility
{
	template<class T>
	class auto_ptr
	{
	public:
		explicit auto_ptr(T* pointer = 0) :pointer_(pointer) {}
		~auto_ptr() { if (pointer_) delete pointer_; }

		auto_ptr<T>& operator=(const auto_ptr<T>& other)
		{
			if (this != &other)
			{
				reset(other.release());
				return *this;
			}
		}

		T&  operator*() const { return *pointer_; }
		T* operator->() const { return pointer_; } //���ﷵ��ֵ������һ�������ˣ����Բ���Ҫ����ֵ��const�������pointer_��ʼ�ղ�����Ӱ���
												   //������ǵ��õ�ʱ�� obj->func() ,����ָ��Ȼ��ָ������ò���->

		T* get() const { return pointer_; }
		T* release() { T*p = get(); pointer_ = NULL; return p; }
		void reset(T* pointer)
		{
			if (pointer_)
				delete pointer_;
			pointer_ = pointer;
		}

		//����ָ���ǿ���ֱ����ʽת����(����ָ������),����auto_ptr<base>��auto_ptr<derived>��������ͬ���������
		//Ȼ��auto_ptr��Ҫʵ�ֵĻ�����������function templates,Ҳ����class���ɺ���������������캯��)
		template<class U>
		auto_ptr<T>(auto_ptr<U>& other) //������һ��������ָ��Ҳ����ָ��һ������������Ҫ���ó�ʼֵ�б���ʵ�ֶ���������"��Ա����Ⱥ"ʵ������
			: pointer_(other.release()) //����Ҫ�����һ����ʽת�����ܹ�ʹU*�ܹ���ʽת����T*����ͨ�����룬��ʵ���˱��������������ת��
		{//������Ϊ��auto_ptr�����Բ�����const

		}

	private:
		T * pointer_;
	};
}

