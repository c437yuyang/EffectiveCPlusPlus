#pragma once
//参考自stl源码剖析3.2 P81

//构造函数()
//析构函数
//operator=()
//拷贝构造函数
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
		T* operator->() const { return pointer_; } //这里返回值是另外一个对象了，所以不需要返回值是const，里面的pointer_是始终不会受影响的
												   //这里就是调用的时候 obj->func() ,返回指针然后指针的内置操作->

		T* get() const { return pointer_; }
		T* release() { T*p = get(); pointer_ = NULL; return p; }
		void reset(T* pointer)
		{
			if (pointer_)
				delete pointer_;
			pointer_ = pointer;
		}

		//内置指针是可以直接隐式转换的(父类指向子类),但是auto_ptr<base>和auto_ptr<derived>是两个不同的类根本就
		//然后auto_ptr想要实现的话，必须利用function templates,也就是class生成函数或叫做泛化构造函数)
		template<class U>
		auto_ptr<T>(auto_ptr<U>& other) //但这样一来，子类指针也可以指向一个父类对象，因此要利用初始值列表来实现对所创建的"成员函数群"实现挑拣
			: pointer_(other.release()) //这里要求存在一个隐式转换，能够使U*能够隐式转换成T*才能通过编译，就实现了必须是子类向父类的转换
		{//这里因为是auto_ptr，所以不能用const

		}

	private:
		T * pointer_;
	};
}

